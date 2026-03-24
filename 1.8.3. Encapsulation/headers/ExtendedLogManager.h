#pragma once
#include "LogManager.h"

class ExtendedLogManager : public LogManager
{
public:
	ExtendedLogManager() = delete;
	ExtendedLogManager(const std::string& time_log, const size_t error, const std::string& type) : LogManager{ time_log, error, type } {};
	~ExtendedLogManager() = default;
	void print_last_type() const;
};