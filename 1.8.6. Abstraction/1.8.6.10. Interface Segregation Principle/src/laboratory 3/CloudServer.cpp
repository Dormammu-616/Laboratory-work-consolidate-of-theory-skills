#include "include/laboratory 3/CloudServer.hpp"
#include <iostream>

CloudServer::CloudServer(const std::string& id) : server_id(id) {};

void CloudServer::execute_task(std::string_view task_name)
{
	std::cout << "[CloudServer] Completing the task '"<< task_name <<"'.\n";
}

std::string CloudServer::get_metrics() const
{
	std::cout << "[CloudServer] Sending metrics: server id '"<< server_id << "'.\n";
	return server_id;
}

void CloudServer::reboot()
{
	std::cout << "[CloudServer] Reboot...\n";
}