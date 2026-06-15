#pragma once
#include "include/laboratory 2/IMover.hpp"

class LogisticsSystem
{
public:
	LogisticsSystem() = default;
	~LogisticsSystem() = default;
	void route_shipment(IMover& mover, std::string_view destination);
};