#pragma once
#include "Lab3/NetworkProcessor.hpp"
#include <memory>
#include <vector>

namespace NetworkManager
{
	void run_network_pipeline(const std::vector<std::shared_ptr<NetworkProcessor>>& processors);
}