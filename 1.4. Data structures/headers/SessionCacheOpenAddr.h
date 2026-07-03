#pragma once
#include "Entry.h"
#include <vector>

class SessionCacheOpenAddr
{
public:
	SessionCacheOpenAddr(size_t initial_capacity = 10);
	~SessionCacheOpenAddr() = default;
	float load_factor() const;
	void emplace(const UserSession session);
	size_t erase(const std::string& session);
	const UserSession* find(const std::string& session) const;
	size_t get_hash_memory() const;
private:
	std::vector<Entry> custom_hash{};
	size_t occupied_count{ 0 };		// учитываются только состояние EMPTY. Данная особенность учитывается как в insert, так и в remove.
	const Entry* find_entry(const std::string& session) const;
	Entry* find_entry(const std::string& session);
	void rehash();
	static constexpr double MAX_LOAD_FACTOR{ 0.75 };
};