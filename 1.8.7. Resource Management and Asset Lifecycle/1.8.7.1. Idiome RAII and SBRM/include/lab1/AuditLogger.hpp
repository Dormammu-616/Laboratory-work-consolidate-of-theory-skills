#pragma once
#include "lab1/AuditFileHandle.hpp"
#include <string>

namespace lab1
{
	class AuditLogger
	{
	public:
		explicit AuditLogger(const std::string& path_file) : handle(std::fopen(path_file.c_str(), "a")) {};
		AuditLogger(const AuditLogger&) = delete;
		AuditLogger& operator=(const AuditLogger&) = delete;
		AuditLogger(AuditLogger&&) = default;
		~AuditLogger() = default;

		void log(const std::string& message);
	private:
		lab1::AuditFileHandle handle;
	};
}