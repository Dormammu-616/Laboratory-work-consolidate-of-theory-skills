#include "LogManager.h"
#include <algorithm>
#include <stdexcept>

void LogManager::add_log(const std::string& time_log, const size_t error, const std::string& type)
{
	Logs new_log{ time_log, error, type };

	auto it_for_insert = std::upper_bound(vec_logs.begin(), vec_logs.end(), new_log,
		[](const Logs& a, const Logs& b) { return a.time_tamp < b.time_tamp; });

	vec_logs.insert(it_for_insert, std::move(new_log));
}

void LogManager::clear_log()
{
	vec_logs.clear();
}

std::string LogManager::last_type_log() const
{
	if (vec_logs.empty())
	{
		throw std::invalid_argument("vector is empty!");
	}

	return { vec_logs.back().type_log };
}