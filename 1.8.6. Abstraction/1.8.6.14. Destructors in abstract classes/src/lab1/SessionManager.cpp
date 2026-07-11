#include "lab1/SessionManager.hpp"
#include <iostream>

void lab1::SessionManager::add_window(std::unique_ptr<IWindow> window)
{
	std::cout << "[SessionManager] Adds a new window...\n";
	active_windows.push_back(std::move(window));
}

void lab1::SessionManager::render_all() const
{
	std::cout << "[SessionManager] Render all windows:\n";

	for (const auto& wind : active_windows)
	{
		wind->render();
		std::cout << "-------------\n";
	}
}