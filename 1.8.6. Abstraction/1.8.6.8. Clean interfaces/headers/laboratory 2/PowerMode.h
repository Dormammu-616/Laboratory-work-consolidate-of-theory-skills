#pragma once
#include <iostream>

enum class PowerMode
{
	Eco, Performance, Standby
};

inline std::ostream& operator<< (std::ostream& os, PowerMode mode)
{
	switch (mode)
	{
	case PowerMode::Eco:			return os << "Eco";
	case PowerMode::Performance:	return os << "Performance";
	case PowerMode::Standby:		return os << "Standby";
	default:						return os << "UNKNOWN MODE";
	}
}