#include "include/laboratory 3/CloudClients.hpp"
#include <iostream>

void TaskScheduler::assign_work(IComputeNode& node, std::string_view task)
{
	std::cout << "[TaskScheduler] Distribution of work '"<< task << "'.\n";
	node.execute_task(task);
}

void TelemetryDashboard::collect_data(const IMonitorable& node)
{
	std::cout << "[TelemetryDashboard] Collecting data...\n";
	const std::string data_from_mode{ node.get_metrics() };
	std::cout << "\tresult: " << data_from_mode << ".\n";
};

void AdminConsole::restart_server(IRebootable& node)
{
	std::cout << "[AdminConsole] Restarting the server...\n";
	node.reboot();
}