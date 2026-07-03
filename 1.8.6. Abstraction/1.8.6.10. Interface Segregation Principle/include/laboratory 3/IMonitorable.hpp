#pragma once
#include <string>

class IMonitorable
{
public:
	[[nodiscard]] virtual std::string get_metrics() const = 0;
	virtual ~IMonitorable() = default;
};