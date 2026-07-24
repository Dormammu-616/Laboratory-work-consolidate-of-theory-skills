#pragma once
#include <cstdint>
#include <string>
#include <iostream>
#include <format>

namespace lab1
{
	struct SystemState
	{
		int64_t uptime{0};
		std::string to_string() const
		{
			std::cout << "[SystemState] Converting a number to a string.\n";
			return std::format("{}", uptime);
		}
	};
}