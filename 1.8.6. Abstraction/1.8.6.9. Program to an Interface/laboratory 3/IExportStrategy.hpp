#pragma once
#include <string_view>

class IExportStrategy
{
public:
	virtual void export_data(std::string_view report_data) const = 0;
	virtual ~IExportStrategy() = default;
};