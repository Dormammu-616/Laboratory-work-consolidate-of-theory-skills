#include "laboratory 3/ReportManager.hpp"
#include <iostream>

ReportManager::ReportManager(std::shared_ptr<IExportStrategy> strategy) : m_strategy(std::move(strategy)) {};

void ReportManager::set_strategy(std::shared_ptr<IExportStrategy> new_strategy)
{
	m_strategy = std::move(new_strategy);
	std::cout << "[ReportManager] The strategy has been successful update!\n";
}

void ReportManager::generate_report(std::string_view data)
{
	if (!m_strategy)
	{
		std::cout << "[ReportManager] Error: strategy not set!\n";
		return;
	}

	std::cout << "[ReportManager] Report preparation...\n";
	m_strategy->export_data(data);
}