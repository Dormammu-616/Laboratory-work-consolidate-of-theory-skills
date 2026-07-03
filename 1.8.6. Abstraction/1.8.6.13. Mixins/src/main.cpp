#include "lab1/CorePacketProcessor.hpp"
#include "lab1/LoggingMixin.hpp"
#include "lab1/ValidationMixin.hpp"
#include <iostream>
#include <vector>
#include <string>

template <typename Processor> void run_pipeline(Processor& proc, const std::vector<std::string>& packets)
{
	std::cout << "[template<run_pipeline>] Start...\n";

	for (const auto& pack : packets)
	{
		proc.process_packet(pack);
		std::cout << "-----\n";
	}

	std::cout << "[template<run_pipeline>] End...\n\n";
}

int main()
{
	std::cout << "*** Start laboratory #1 - Base mixin ***\n\n";

	using ProdProcessor = lab1::CorePacketProcessor;
	using DebugProcessor = lab1::LoggingMixin<lab1::CorePacketProcessor>;
	using SafeDebugProcessor = lab1::ValidationMixin<lab1::LoggingMixin<lab1::CorePacketProcessor>>;
	using WrongOrderProcessor = lab1::LoggingMixin<lab1::ValidationMixin<lab1::CorePacketProcessor>>; // for expreriment

	const std::vector<std::string> packet{ "Trade_100$", "ERROR_Corrupted", "Trade_200$" };

	std::cout << "\t--- Test 1: Core (ProdProcessor) ---\n";
	ProdProcessor prod_proc{};
	run_pipeline(prod_proc, packet);

	std::cout << "\t--- Test 2: Core + logging (DebugProcessor) ---\n";
	DebugProcessor debug_proc{};
	run_pipeline(debug_proc, packet);

	std::cout << "\t--- Test 3: Core + logging + validation (SafeDebugProcessor) ---\n";
	SafeDebugProcessor safe_proc{};
	run_pipeline(safe_proc, packet);

	std::cout << "\t--- Test 4 (experiment): Logging + validation + core (WrongOrderProcessor) ---\n";
	WrongOrderProcessor wrong_order_proc{};
	run_pipeline(wrong_order_proc, packet);

	std::cout << "*** End laboratory #1 ***\n\n";


	std::cout << "*** Start laboratory #2 -  ***\n";

	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";

	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}