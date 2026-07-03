#pragma once
#include "laboratory 3/IExportStrategy.hpp"
#include <memory>

class ReportManager
{
public:
	ReportManager() = delete;
	ReportManager(std::shared_ptr<IExportStrategy> strategy);
	~ReportManager() = default;
	void set_strategy(std::shared_ptr<IExportStrategy> new_strategy);
	void generate_report(std::string_view data);
private:
	std::shared_ptr<IExportStrategy> m_strategy;
};