#pragma once
#include <optional>

class ISensor
{
public:
	virtual std::optional<double> read_data() const = 0;
	virtual ~ISensor() = default;
};