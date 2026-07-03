#pragma once
#include "Lab2/DataExporter.hpp"
#include <vector>
#include <memory>

namespace ExportManager
{
	void process_exports(const std::vector<std::shared_ptr<DataExporter>>& exporters);
}