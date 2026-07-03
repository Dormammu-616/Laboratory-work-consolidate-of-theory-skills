#pragma once
#include "include/laboratory 3/IComputeNode.hpp"
#include "include/laboratory 3/IMonitorable.hpp"
#include "include/laboratory 3/IRebootable.hpp"
#include <string_view>

class TaskScheduler
{
public:
	TaskScheduler() = default;
	void assign_work(IComputeNode& node, std::string_view task);
	~TaskScheduler() = default;
};

class TelemetryDashboard
{
public:
	TelemetryDashboard() = default;
	void collect_data(const IMonitorable& node);
	~TelemetryDashboard() = default;
};

class AdminConsole
{
public:
	AdminConsole() = default;
	void restart_server(IRebootable& node);
	~AdminConsole() = default;
};
