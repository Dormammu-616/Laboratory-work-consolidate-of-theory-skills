#include "LogInspector.h"
#include <map>
#include <iostream>

void LogInspector::print_of_statistics(const LogManager& manager) const
{
	if (manager.vec_logs.empty())
	{
		std::cout << "The manager is empty!\n";
		return;
	}

	std::map<size_t, size_t> error_frequency{};

	for (const auto& log : manager.vec_logs)
	{
		error_frequency[log.error_code]++;
	}

	std::cout << "# error | frequency\n";
	for (const auto& error : error_frequency)
	{
		std::cout << error.first << "\t| " << error.second << "\n";
	}
	std::cout << "\n";
}