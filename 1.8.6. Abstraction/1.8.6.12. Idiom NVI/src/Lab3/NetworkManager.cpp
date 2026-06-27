#include "Lab3/NetworkManager.hpp"
#include <iostream>

void NetworkManager::run_network_pipeline(const std::vector<std::shared_ptr<NetworkProcessor>>& processors)
{
	std::cout << "\t[NetworkManager] Starting network pipeline...\n\n";

	for (const auto& process : processors)
	{
		process->process_request();
	}

	std::cout << "\t[NetworkManager] End network pipeline...\n";
}