#include <iostream>
#include "lab1/CryptoBuffer.hpp"
#include "lab1/GatewayRouter.hpp"
#include "lab2/EventDispatcher.hpp"
#include "lab2/SecurityEvent.hpp"
#include "lab3/LogAggregator.hpp"

int main()
{
	std::cout << "*** Start laboratory #1 - Safe Resource Absorption ***\n";
	{
		std::cout << "--- Creating original buffer ---\n";
		lab1::CryptoBuffer buffer_original{ 1024 };
		buffer_original.get_memory_address();

		std::cout << "\n--- Creating copy buffer ---\n";
		lab1::CryptoBuffer buffer_copy{ buffer_original };
		buffer_copy.get_memory_address();

		std::cout << "\n--- Move copy buffer ---\n";
		lab1::GatewayRouter router{};
		router.set_payload(std::move(buffer_copy));

		std::cout << "\n--- Buffer copy after moved ---\n";
		buffer_copy.get_memory_address();
		std::cout << "\n";
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 - Perfect Forwarding ***\n";
	{
		std::cout << "--- Instantiating the event dispatcher ---\n";
		lab2::EventDispatcher dispatcher{};

		std::cout << "\n--- Scenario 1: routing lvalue (copy) ---\n";
		lab2::SecurityEvent cacher_event{ 1, "Login_Failed" };
		dispatcher.dispatch(cacher_event);

		std::cout << "\n--- Scenario 2: routing prvalue (move) ---\n";
		dispatcher.dispatch(lab2::SecurityEvent{ 2, "SQL_Injection_Attempt" });

		std::cout << "\n--- Scenario 3: routing xvalue (move) ---\n";
		lab2::SecurityEvent obsolete_event{ 3, "Token_Expired" };
		dispatcher.dispatch(std::move(obsolete_event));
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 - Architecture Zero-Overhead ***\n";
	{
		std::cout << "--- Scenario 1: Proof of RVO and the Zero Rule ---\n";
		lab3::LogAggregator aggregator{ lab3::LogAggregator::create_aggregator("NetworkNode") };

		std::cout << "\n--- Scenario 2: Moving a composite object ---\n";
		lab3::LogAggregator backup_aggregator{ std::move(aggregator) };
		std::cout << "\tsize backup aggregator after 'move':\t" << backup_aggregator.get_size_log() << "\n";
		std::cout << "\tsize original aggregator after 'move':\t" << aggregator.get_size_log() << "\n";

		std::cout << "\n--- Scenario 3: Architectural test on UB ---\n";
		std::string_view dangling{ lab3::LogAggregator::create_aggregator("Temp").get_node_name() };
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}