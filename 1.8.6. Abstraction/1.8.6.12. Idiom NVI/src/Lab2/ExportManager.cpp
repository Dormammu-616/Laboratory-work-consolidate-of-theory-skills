#include "Lab2/ExportManager.hpp"
#include <iostream>

void ExportManager::process_exports(const std::vector<std::shared_ptr<DataExporter>>& exporters)
{
	std::cout << "\t[ExportManager] Starting batch export.\n\n";

	for (const auto& data : exporters)
	{
		data->export_data();
	}

	std::cout << "\t[ExportManager] End batch export.\n";
}