#pragma once
#include "LogManager.h"

class LogInspector
{
public:
	LogInspector() = default;
	~LogInspector() = default;
	void print_of_statistics(const LogManager& manager) const;
};