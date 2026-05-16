#pragma once
#include <SessionCacheOpenAddr.h>
#include "Custom_Hash.h"
#pragma warning(disable: 5045)

SessionCacheOpenAddr::SessionCacheOpenAddr(size_t initial_capacity) : custom_hash(initial_capacity) {};

void SessionCacheOpenAddr::rehash()
{
	const size_t NEW_CAPACITY{ custom_hash.size() * 2 };
	std::vector<Entry> new_hash{ NEW_CAPACITY };
	occupied_count = 0;

	for (auto& bucket : custom_hash)
	{
		if (bucket.user_state == State::OCCUPIED)
		{
			const uint64_t HASH_IND{ Custom_Hash::calc_poly_hash(bucket.user_data.session_token) % NEW_CAPACITY };

			for (size_t i = 0; i < NEW_CAPACITY; ++i)
			{
				size_t cur_ind{ (HASH_IND + i) % NEW_CAPACITY };
				if (new_hash[cur_ind].user_state == State::EMPTY)
				{
					new_hash[cur_ind].user_data = std::move(bucket.user_data);
					new_hash[cur_ind].user_state = State::OCCUPIED;
					++occupied_count;
					break;
				}
			}
		}
	}

	custom_hash = std::move(new_hash);
}

const Entry* SessionCacheOpenAddr::find_entry(const std::string& session) const
{
	const size_t CAPACITY{ custom_hash.size() };

	if (CAPACITY == 0) return nullptr;
	const size_t START_IND{ Custom_Hash::calc_poly_hash(session) % CAPACITY };

	for (size_t i = 0; i < CAPACITY; ++i)
	{
		const size_t CUR_IND{ (START_IND + i) % CAPACITY };
		const Entry* CELL{ &custom_hash[CUR_IND] };

		if (CELL->user_state == State::EMPTY)	return nullptr;
		if (CELL->user_data.session_token == session && CELL->user_state == State::OCCUPIED)		return CELL;
	}

	return nullptr;
}

Entry* SessionCacheOpenAddr::find_entry(const std::string& session)
{
	return const_cast<Entry*>(static_cast<const SessionCacheOpenAddr*>(this)->find_entry(session));
}

float SessionCacheOpenAddr::load_factor() const
{
	if (custom_hash.empty()) return { 1.0 };
	return (static_cast<float>(occupied_count) / static_cast<float>(custom_hash.size()));
}

void SessionCacheOpenAddr::emplace(const UserSession data)
{
	if (load_factor() > MAX_LOAD_FACTOR)
	{
		rehash();
	}

	const size_t IND_BY_HASH{ Custom_Hash::calc_poly_hash(data.session_token) % custom_hash.size() };
	int ind_for_insert{ -1 };

	for (size_t i = 0; i < custom_hash.size(); ++i)
	{
		const size_t CUR_IND{ (IND_BY_HASH + i) % custom_hash.size() };
		Entry& cur_cell{ custom_hash[CUR_IND] };

		if (cur_cell.user_data.session_token == data.session_token && cur_cell.user_state == State::OCCUPIED)
		{
			return;
		}
		else if (cur_cell.user_state == State::DELETED && ind_for_insert == -1)
		{
			ind_for_insert = static_cast<int>(CUR_IND);
		}
		else if (cur_cell.user_state == State::EMPTY)
		{
			if (ind_for_insert == -1) ind_for_insert = static_cast<int>(CUR_IND);
			break;
		}
	}

	if (ind_for_insert != -1)
	{
		Entry& cell{ custom_hash[static_cast<uint64_t>(ind_for_insert)] };
		if (cell.user_state == State::EMPTY)	{ ++occupied_count; }
		cell.user_data = data;
		cell.user_state = State::OCCUPIED;
	}
}

size_t SessionCacheOpenAddr::erase(const std::string& session)
{
	// метка occupied_count не величивается, чтобы не замедлять алгоритм insert из-за длины цепочек, которые не EMPTY.

	if (custom_hash.empty())		return 0;

	Entry* target_cell{ find_entry(session) };

	if (target_cell == nullptr)		return 0;

	target_cell->user_state = State::DELETED;
	target_cell->user_data.session_token.clear();
	return 1;
}

const UserSession* SessionCacheOpenAddr::find(const std::string& session) const
{
	const Entry* CELL { find_entry(session) };

	if (CELL == nullptr) return {};

	return &CELL->user_data;
}

size_t SessionCacheOpenAddr::get_hash_memory() const
{
	return custom_hash.capacity() * sizeof(Entry);
}