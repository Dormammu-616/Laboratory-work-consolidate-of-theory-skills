#include "lab1/AuditLogger.hpp"
#include <iostream>

void test_early_exit(bool abort_early)
{
	lab1::AuditLogger log("early_exit.log");
	log.log("Start processing...");

	if (abort_early)
	{
		std::cout << "\t[test_early_exit] Aborting...\n";
		return;
	}

	log.log("\t[test_early_exit] Finished processing...");
}

int main()
{
	std::cout << "*** Start laboratory #1 - Encapsulating a Legacy C-API ***\n";
	{
		std::cout << "--- Scenario: standard operation ---\n";
		{
			lab1::AuditLogger logger{ "example_path_file.log" };
			logger.log("31.07.2026 21:10 example #1");
			logger.log("31.07.2026 21:15 example #2");
			logger.log("31.07.2026 21:20 example #3");
		}

		std::cout << "\n--- Scenario: early exit ---\n";
		{
			test_early_exit(true);
		}

		std::cout << "\n--- Scenario: initialization error interception ---\n";
		{
			try
			{
				lab1::AuditLogger logger("Z:/non_existent_directory/forbidden.log");
			}
			catch (const std::runtime_error& e)
			{
				std::cout << " Exception caught: " << e.what() << "\n";
			}
		}
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}