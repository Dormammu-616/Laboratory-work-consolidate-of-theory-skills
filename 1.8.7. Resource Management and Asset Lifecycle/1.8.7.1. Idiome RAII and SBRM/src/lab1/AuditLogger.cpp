#include "lab1/AuditLogger.hpp"
#include <iostream>

void lab1::AuditLogger::log(const std::string& message)
{
	std::cout << "[AuditLogger] Logging...\n";
	const std::string formatted_str{ "[AuditLogger] Log '" + message + "'.\n" };
	handle.write(formatted_str.data(), formatted_str.size());
}