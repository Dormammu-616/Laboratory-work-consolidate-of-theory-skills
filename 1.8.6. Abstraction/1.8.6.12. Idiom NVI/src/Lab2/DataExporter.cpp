#include "Lab2/DataExporter.hpp"
#include <iostream>

void DataExporter::export_data()
{
	std::cout << "[DataExporter] Opening file stream...\n";

	format_data();

	std::cout << "[DataExporter] Closing file stream...\n\n";
}

void DataExporter::format_data() const
{
	std::cout << "[DataExporter] Data as Raw text...\n";
}
