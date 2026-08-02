#include "lab1/AuditLogger.hpp"
#include "lab2/DatabaseNode.hpp"
#include "lab3/SecureBuffer.hpp"
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

void update_config_risky(lab3::SecureBuffer& target, size_t new_size, bool should_throw)
{
	lab3::SecureBuffer temp{ new_size };

	if (should_throw == true)
	{
		throw std::runtime_error("Simulated network/hardware failure during config fetch!");
	}

	target.swap(temp);
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
				std::cout << "Exception caught: " << e.what() << "\n";
			}
		}
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 - Transactional Construction ***\n";
	{
		std::cout << "--- Successful start ---\n";
		{
			lab2::DatabaseNode node{ "local.db", 8080 };
		}

		std::cout << "--- Rollback on failure ---\n";
		{
			try
			{
				lab2::DatabaseNode crasher_node{ "local.db", 80 };
			}
			catch (std::exception& e)
			{
				std::cout << "Exception caught: " << e.what() << "\n";
			}
		}
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 - Strong Exception Guarantee ***\n";
	{
		std::cout << "--- Demonstration of Copy-and-Swap on assignment ---\n";
		{
			lab3::SecureBuffer buf_one{ 100 };
			lab3::SecureBuffer buf_two{ 500 };

			std::cout << "\t[main] Call operator=\n";
			buf_one = buf_two;
		}

		std::cout << "\n--- Testing for strong exception guarantees ---\n";
		{
			lab3::SecureBuffer target{ 10 };

			std::cout << "Before the finction call the first symbol is '"<< target.get_first_char() <<"', the size is '"<< target.size() <<"'\n";

			try
			{
				update_config_risky(target, 1000, true);
			}
			catch (const std::exception& e)
			{
				std::cout << "Error: " << e.what() << "\n";
			}

			std::cout << "After the finction call the first symbol is '" << target.get_first_char() << "', the size is '" << target.size() << "'\n";
		}
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}