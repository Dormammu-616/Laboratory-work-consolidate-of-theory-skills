#pragma once
#include "laboratory 3/IExportStrategy.hpp"

class CsvExportStrategy : public IExportStrategy
{
public:
	CsvExportStrategy() = default;
	~CsvExportStrategy() = default;
	void export_data(std::string_view report_data) const override;
};