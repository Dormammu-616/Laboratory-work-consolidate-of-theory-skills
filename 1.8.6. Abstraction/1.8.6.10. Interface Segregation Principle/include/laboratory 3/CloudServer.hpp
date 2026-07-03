#pragma once
#include "include/laboratory 3/IComputeNode.hpp"
#include "include/laboratory 3/IMonitorable.hpp"
#include "include/laboratory 3/IRebootable.hpp"

class CloudServer : public IComputeNode, public IMonitorable, public IRebootable
{
public:
	CloudServer() = delete;
	CloudServer(const std::string& id);
	CloudServer(const CloudServer&) = delete;
	CloudServer& operator=(const CloudServer&) = delete;
	~CloudServer() = default;
	void execute_task(std::string_view task_name) override;
	[[nodiscard]] std::string get_metrics() const override;
	void reboot() override;
private:
	std::string server_id{};
};