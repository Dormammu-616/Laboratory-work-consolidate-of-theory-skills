#include "include/laboratory 2/LegacyRobot.hpp"
#include <iostream>

void LegacyRobot::weld()
{
	std::cout << "[LegacyRobot] Welding metal..\n";
}

void LegacyRobot::paint()
{
	std::cout << "[LegacyRobot] Painting...\n";
}

void LegacyRobot::carry_item(std::string_view target)
{
	std::cout << "[LegacyRobot] Carrying item to: '"<<target<<"'\n";
}