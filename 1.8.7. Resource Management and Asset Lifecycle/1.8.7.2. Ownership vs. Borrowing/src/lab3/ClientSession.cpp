#include "lab3/ClientSession.hpp"
#include <iostream>

lab3::ClientSession::ClientSession(int64_t id) : session_id_(id)
{
	std::cout << "[ClientSession] Session '"<< session_id_ << "' created.\n";
}

lab3::ClientSession::~ClientSession()
{
	std::cout << "[ClientSession] Session '" << session_id_ << "' destroyed.\n";
}

int64_t lab3::ClientSession::get_id() const
{
	return session_id_;
}

void lab3::ClientSession::ping() const
{
	std::cout << "[ClientSession] The current session is active.\n";
}