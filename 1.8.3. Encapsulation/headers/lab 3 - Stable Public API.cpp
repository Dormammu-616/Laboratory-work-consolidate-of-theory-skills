#include "lab 3 - Stable Public API.h"
#include <iostream>
#include "LogManager.h"
#include "LogInspector.h"
#include "ExtendedLogManager.h"

void Stable_Public_API::run_lab()
{
	std::cout << "***\tLab # 3 - Stable Public API\t***\n";

	LogManager manager{ "2026-03-24", 5, "ERROR" };
	std::cout << "--- Created LogManager!---\n";
	
	std::cout << "--- Adding logs to the manager ---\n";
	manager.add_log("2026-03-24", 7, "INFO");
	manager.add_log("2026-03-18", 7, "WARNING");
	manager.add_log("2026-02-10", 1, "INFO");

	LogInspector inspector{};
	std::cout << "--- Created LogInspector!---\n";

	// ÎØÈÁÊÀ ÊÎÌÏÈËßÒÎÐÀ - íåâîçìîæíî îáðàòèòüñÿ ê ïðèâàòíûì ïîëÿì LogManager
	//inspector.vec_logs.front() = Log{ "2026-01-01", 1, "ERROR" };

	std::cout << "--- Call statistics\n";
	inspector.print_of_statistics(manager);

	std::cout << "--- Clear manager ---\n";
	manager.clear_log();
	std::cout << "--- Checking the manager's content through the advanced manager ---\n";
	inspector.print_of_statistics(manager);

	ExtendedLogManager extended_manager{"2026-01-05", 4, "ERROR"};
	std::cout << "--- Created ExtendedLogManager!---\n";

	std::cout << "--- Adding logs to the extended manager ---\n";
	extended_manager.add_log("2026-02-10", 4, "INFO");
	extended_manager.add_log("2026-02-01", 3, "WARNING");

	std::cout << "--- Calling extended logic ---\n";
	extended_manager.print_last_type();

	std::cout << "\n***\tThe end labs #2\t***\n";
}