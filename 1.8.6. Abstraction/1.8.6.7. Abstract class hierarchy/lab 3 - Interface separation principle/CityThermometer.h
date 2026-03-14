#pragma once
#include "ITelemetrySensor.h"

class City_Thermometer : public ITelemetry_Sensor
{
public:
	std::string takeMeasurement() override;
	~City_Thermometer() override = default;
};