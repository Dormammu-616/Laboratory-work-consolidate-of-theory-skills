#include "include/laboratory 2/LogisticsSystem.hpp"
#include <iostream>

void LogisticsSystem::route_shipment(IMover& mover, std::string_view destination)
{
	std::cout << "[LogisticsSystem] Start of the shipment route...\n";

	mover.move_cargo(destination);
}