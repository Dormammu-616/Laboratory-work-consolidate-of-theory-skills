#pragma once
#include <cstdint>
#include <iostream>
#include <string>

namespace lab3
{
	class DatabaseCleanup
	{
	public:
		bool execute()
		{
			tables_cleaned += 10;
			std::cout << "[DatabaseCleanup] Tables cleaned so far: '"<< tables_cleaned << "'\n";
			return true;
		}
	private:
		int64_t tables_cleaned{ 0 };
	};

	class EmailNotification
	{
	public:
		EmailNotification(const std::string& receiver) : recipient(receiver) {};
		bool execute()
		{
			std::cout << "[EmailNotification] Sending email to '"<< recipient << "'...\n";
			return true;
		}
	private:
		std::string recipient{};
	};

	namespace Legacy
	{
		class ReportGenerator
		{
		public:
			bool execute()
			{
				std::cout << "[ReportGenerator] CRITICAL ERROR: Server unreachable!.\n";
				return false;
			}
		};
	}
}