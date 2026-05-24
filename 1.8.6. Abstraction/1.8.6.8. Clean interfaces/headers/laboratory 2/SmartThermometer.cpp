#include <laboratory 2/SmartThermometer.h>
#include <iostream>

SmartThermometer::SmartThermometer(double level, PowerMode mode, double temp, std::string_view network) :
	battery_level(level), power_mode(mode), temperature(temp), cur_network(std::move(network)), is_network_conected(!cur_network.empty())
{
	std::cout << "[SmartThermometer] Thermometer created! Value: level '"<< level << "', PowerMode'"<< mode << "', temperature '"<< temp << "', network '"<< network << "'.\n";
};

double SmartThermometer::get_battery_level() const
{
	std::cout << "[SmartThermometer] Successful get battery level on SmartThermometer\n";
	return battery_level;
}

void SmartThermometer::set_power_mode(PowerMode mode)
{
	power_mode = mode;
	std::cout << "[SmartThermometer] Successful set power mode\n";
}

bool SmartThermometer::is_connected() const
{
	std::cout << "[SmartThermometer] Check connected SmartThermometer\n";
	return is_network_conected;
}

std::optional<double> SmartThermometer::read_data() const
{
	if (is_connected() && battery_level > 0.0)
	{
		std::cout << "[SmartThermometer] Successful read data on SmartThermometer\n";
		return temperature;
	}

	std::cout << "[SmartThermometer] Unsuccessful read data on SmartThermometer\n";
	return std::nullopt;
}

void SmartThermometer::connect(std::string_view network)
{
	if (!network.empty())
	{
		is_network_conected = true;
		cur_network = network;
		std::cout << "[SmartThermometer] Connected successful on SmartThermometer\n";
	}
}

void SmartThermometer::disconnect()
{
	is_network_conected = false;
	cur_network.clear();
	std::cout << "[SmartThermometer] Disconnect successful on SmartThermometer\n";
}