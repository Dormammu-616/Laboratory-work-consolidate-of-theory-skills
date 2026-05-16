#include <SessionCacheChaining.h>
#include <Custom_Hash.h>
#pragma warning(disable: 5045) // для строчки rehash в SessionCacheChaining::insert

SessionCacheChaining::SessionCacheChaining(size_t initial_capacity) : custom_hash(initial_capacity) {};

void SessionCacheChaining::rehash()
{
	const size_t NEW_CAPACITY{ custom_hash.size() * 2 + 1 };
	std::vector<std::list<UserSession>> new_hash{ NEW_CAPACITY };
	
	for (const auto& bucket : custom_hash)
	{
		for (const auto& data : bucket)
		{
			const size_t NEW_IND{ Custom_Hash::calc_poly_hash(data.session_token) % NEW_CAPACITY };
			new_hash[NEW_IND].emplace_back(data);
		}
	}

	custom_hash = std::move(new_hash);
}

float SessionCacheChaining::load_factor() const
{
	if (custom_hash.empty()) return { 1.0 };
	return (static_cast<float>(num_elem_in_custom_hash) / static_cast<float>(custom_hash.size()));
}

void SessionCacheChaining::emplace(const UserSession data)
{
	const size_t IND_FOR_INSERT{ Custom_Hash::calc_poly_hash(data.session_token) % custom_hash.size() };

	for (auto& data_of_elem : custom_hash[IND_FOR_INSERT])
	{
		if (data_of_elem.session_token == data.session_token)
		{
			data_of_elem.access_level = data.access_level;
			data_of_elem.user_id = data.user_id;
			return;
		}
	}
	
	custom_hash[IND_FOR_INSERT].emplace_back(data);
	++num_elem_in_custom_hash;

	
	if (load_factor() > MAX_LOAD_FACTOR)
	{
		rehash();
	}
}

size_t SessionCacheChaining::erase(const std::string& session)
{
	if (custom_hash.empty())	return 0;

	const size_t IND_SESSION{ Custom_Hash::calc_poly_hash(session) % custom_hash.size() };
	auto& session_list{ custom_hash[IND_SESSION] };

	auto it_session{ std::find_if(session_list.begin(), session_list.end(), [&session](const UserSession& ses) { return ses.session_token == session; }) };

	if (it_session == session_list.end()) return 0;

	session_list.erase(it_session);
	--num_elem_in_custom_hash;
	return 1;
}

const UserSession* SessionCacheChaining::find(const std::string& session) const
{
	if (custom_hash.empty()) return nullptr;

	const size_t IND_BY_SESSION{ Custom_Hash::calc_poly_hash(session) % custom_hash.size() };

	for (const auto& data : custom_hash[IND_BY_SESSION])
	{
		if (data.session_token == session)
		{
			return &data;
		}
	}

	return nullptr;
}

size_t SessionCacheChaining::get_hash_memory() const
{
	const size_t VECTOR_MEMORY{ custom_hash.capacity() * sizeof(std::list<UserSession>) };
	const size_t NODES_MEMORY{ num_elem_in_custom_hash * (sizeof(UserSession) + sizeof(void*) * 2) };

	return VECTOR_MEMORY+NODES_MEMORY;
}