#include "lab3/SessionManager.hpp"
#include <iostream>

std::shared_ptr<lab3::ClientSession> lab3::SessionManager::create_session(int64_t id)
{
	std::cout << "[SessionManager] Creating a new session.\n";

	active_session_.push_back(std::make_shared<lab3::ClientSession>(id));
	return active_session_.back();
}

void lab3::SessionManager::drop_session(int64_t id)
{
	std::cout << "[SessionManager] Dropping session.\n";
	std::erase_if(active_session_, [id](const auto& ptr) { return ptr && (ptr->get_id() == id); });
}