#include "lab2/ConnectionPool.hpp"

void lab2::ConnectionPool::add_policy(std::shared_ptr<lab2::SecurityPolicy> policy)
{
	policies.push_back(std::move(policy));
	std::cout << "[ConnectionPool] A new policy has been added.\n";
}

void lab2::ConnectionPool::verify_all() const
{
	std::cout << "\t[ConnectionPool] Verification...\n";

	for (const auto& pol : policies)
	{
		pol->check_clearance();
		std::cout << "\t-------\n";
	}
}