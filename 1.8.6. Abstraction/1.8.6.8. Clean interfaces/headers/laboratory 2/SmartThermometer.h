#pragma once
#include <laboratory 2/IConnectable.h>
#include <laboratory 2/IPowerManaged.h>
#include <laboratory 2/PowerMode.h>
#include <laboratory 2/ISensor.h>

class SmartThermometer : public IConnectable, public IPowerManaged, public ISensor
{
public:
	SmartThermometer() = default;
	SmartThermometer(double level, PowerMode mode, double temp, std::string_view network);
	double get_battery_level() const override;
	void set_power_mode(PowerMode mode) override;
	bool is_connected() const override;
	std::optional<double> read_data() const override;
	void connect(std::string_view network) override;
	void disconnect() override;
	~SmartThermometer() = default;
private:
	double battery_level{0.0};
	PowerMode power_mode{PowerMode::Standby};
	double temperature{0.0};
	std::string cur_network{""};
	bool is_network_conected{false};
};