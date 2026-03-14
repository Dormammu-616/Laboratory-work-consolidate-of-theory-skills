#pragma once
#include <string>

class ITelemetry_Sensor
{
public:
	virtual ~ITelemetry_Sensor() = default;
	virtual std::string takeMeasurement() = 0;
};