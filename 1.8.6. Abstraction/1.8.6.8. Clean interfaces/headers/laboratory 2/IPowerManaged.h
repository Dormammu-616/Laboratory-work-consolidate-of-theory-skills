#pragma once
#include <laboratory 2/PowerMode.h>

class IPowerManaged
{
public:
	virtual double get_battery_level() const = 0;
	virtual void set_power_mode(PowerMode mode) = 0;
	virtual ~IPowerManaged() = default;
};