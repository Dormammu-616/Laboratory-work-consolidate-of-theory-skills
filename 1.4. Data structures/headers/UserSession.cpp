#include "UserSession.h"

UserSession::UserSession() : session_token{}, user_id{ 0 }, access_level{ 0 } {};

UserSession::UserSession(const std::string& token, const uint64_t id, const int level) : session_token(token), user_id(id), access_level(level) {};