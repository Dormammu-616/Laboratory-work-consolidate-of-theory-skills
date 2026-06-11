#include "laboratory 3/JsonExportStrategy.hpp"
#include <iostream>

void JsonExportStrategy::export_data(std::string_view report_data) const
{
	std::cout << "[JSON Export] Data download: 'data' - '"<<report_data<<"'.\n";
}