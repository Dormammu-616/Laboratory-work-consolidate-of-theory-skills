#include "include/laboratory 2/RobotMoverAdapter.hpp"
#include <iostream>

RobotMoverAdapter::RobotMoverAdapter(IUniversalRobotAPI& robot) : legacy_robot(robot) {}

void RobotMoverAdapter::move_cargo(std::string_view destination)
{
	std::cout << "[RobotMoverAdapter] Moved...\n";

	legacy_robot.carry_item(destination);
}