#pragma once
#include <string>

class ITelemetrySender
{
public:
	virtual void send_metrics(const std::string& name, double val) = 0;
	virtual bool is_available() const = 0;
	virtual ~ITelemetrySender() = default;
};