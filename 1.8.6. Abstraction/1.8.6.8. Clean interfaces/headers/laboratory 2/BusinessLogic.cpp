#include <laboratory 2/BusinessLogic.h>
#include <iostream>

void optimize_battery(IPowerManaged& device)
{
	const double LOW_BATTERY_LEVEL{ 20.0 };

	std::cout << "[BusinessLogic] Run optimize battery\n";

	if (device.get_battery_level() < LOW_BATTERY_LEVEL)
	{
		std::cout << "\tBattery level is low. Change of PowerMode\n";
		device.set_power_mode(PowerMode::Eco);
	}
	else
	{
		std::cout << "\tBattery level is normal. PowerMode does not change\n";
	}

	std::cout << "[BusinessLogic] Completion optimize battery\n";
}

void sync_sensor_data(IConnectable& network_device, ISensor& sensor)
{
	std::cout << "[BusinessLogic] Run sync sensor data\n";

	if (network_device.is_connected())
	{
		std::cout << "\tDevice connected!\n";

		auto data = sensor.read_data();

		if (data.has_value())
		{
			std::cout << "\tValue data: " << data.value() << "\n";
		}
		else
		{
			std::cout << "\tERROR: data not exist.\n";
		}
	}
	else
	{
		std::cout << "\tDevice not connected!\n";
	}

	std::cout << "[BusinessLogic] Completion sync sensor data\n";
}
