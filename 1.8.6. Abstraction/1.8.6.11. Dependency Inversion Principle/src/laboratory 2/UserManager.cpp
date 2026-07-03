#include "include/laboratory 2/UserManager.hpp"
#include <iostream>

BusinessLogic::UserManager::UserManager(std::shared_ptr<BusinessLogic::INotifier> notifier) : p_notifier(std::move(notifier)) {}

void BusinessLogic::UserManager::register_user(std::string_view username) const
{
	std::cout << "[BusinessLogic::UserManager] User '"<< username <<"' sucessfully registered.\n";
	p_notifier->send_notification("Welcome to our platform!");
}