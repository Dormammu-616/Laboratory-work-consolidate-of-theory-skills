#pragma once
#include "laboratory 3/IExportStrategy.hpp"

class JsonExportStrategy : public IExportStrategy
{
public:
	JsonExportStrategy() = default;
	~JsonExportStrategy() = default;
	void export_data(std::string_view report_data) const override;
};