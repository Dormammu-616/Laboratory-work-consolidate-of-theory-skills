#pragma once

class ICloudResource	// 5 долгов
{
public:
	virtual void deploy() = 0;
	virtual void destroy() = 0;
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual double getHourlyRate() = 0;
	virtual ~ICloudResource() = default;
};