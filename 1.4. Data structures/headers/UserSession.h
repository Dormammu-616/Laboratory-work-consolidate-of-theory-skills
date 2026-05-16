#pragma once
#include <string>
#include <cstdint>

struct UserSession
{
	std::string session_token;
	uint64_t user_id;
	uint8_t padding[4]{};
	int access_level;
	UserSession(const std::string& token, const uint64_t id, const int level);
	UserSession();
};