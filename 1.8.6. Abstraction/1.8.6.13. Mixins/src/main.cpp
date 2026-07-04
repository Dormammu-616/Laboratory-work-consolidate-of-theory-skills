#include "lab1/CorePacketProcessor.hpp"
#include "lab1/LoggingMixin.hpp"
#include "lab1/ValidationMixin.hpp"
#include "lab2/Player.hpp"
#include "lab2/Enemy.hpp"
#include <iostream>
#include <vector>
#include <string>

namespace lab1
{
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
}

namespace lab2
{
	template <typename... Entities> void render_scene(const Entities&... entities)
	{
		(entities.render_frame(), ...);
	}
}

namespace lab3
{

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
	lab1::run_pipeline(prod_proc, packet);

	std::cout << "\t--- Test 2: Core + logging (DebugProcessor) ---\n";
	DebugProcessor debug_proc{};
	lab1::run_pipeline(debug_proc, packet);

	std::cout << "\t--- Test 3: Core + logging + validation (SafeDebugProcessor) ---\n";
	SafeDebugProcessor safe_proc{};
	lab1::run_pipeline(safe_proc, packet);

	std::cout << "\t--- Test 4 (experiment): Logging + validation + core (WrongOrderProcessor) ---\n";
	WrongOrderProcessor wrong_order_proc{};
	lab1::run_pipeline(wrong_order_proc, packet);

	std::cout << "*** End laboratory #1 ***\n\n";


	std::cout << "*** Start laboratory #2 - CRTP Mixins and C++17 fold expressions ***\n";

	std::cout << "[Player] Active count before a new scope: " << lab2::Player::get_active_count() << "\n";
	std::cout << "[Enemy] Active count before a new scope: " << lab2::Enemy::get_active_count() << "\n\n";

	{
		std::cout << "\tCreated a new scope.\n";
		lab2::Player p1{};
		std::cout << "\tCreated player 'p1'.\n";

		lab2::Enemy e1{};
		lab2::Enemy e2{};
		std::cout << "\tCreated enemy 'e1' and 'e2'.\n";

		std::cout << "\t[Player] Active count: " << lab2::Player::get_active_count() << "\n";
		std::cout << "\t[Enemy] Active count: " << lab2::Enemy::get_active_count() << "\n";

		lab2::render_scene(p1, e1, e2);

		std::cout << "\tExiting a new scope\n";
	}

	std::cout << "[Player] Active count after a new scope: " << lab2::Player::get_active_count() << "\n";
	std::cout << "[Enemy] Active count after a new scope: " << lab2::Enemy::get_active_count() << "\n\n";

	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";

	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}