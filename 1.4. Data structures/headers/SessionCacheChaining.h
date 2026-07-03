#pragma once
#include "UserSession.h"
#include <vector>
#include <list>

class SessionCacheChaining
{
public:
	SessionCacheChaining(size_t initial_capacity = 10);
	~SessionCacheChaining() = default;
	float load_factor() const;
	void emplace(const UserSession data);
	size_t erase(const std::string& session);
	const UserSession* find(const std::string& session) const;
	size_t get_hash_memory() const;
private:
	std::vector<std::list<UserSession>> custom_hash{};
	void rehash();
	static constexpr double MAX_LOAD_FACTOR{ 0.75 };
	size_t num_elem_in_custom_hash{0};
};