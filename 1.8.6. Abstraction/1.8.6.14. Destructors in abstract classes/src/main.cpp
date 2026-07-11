#include "lab1/SessionManager.hpp"
#include "lab1/ConsoleWindow.hpp"
#include "lab1/HardwareAcceleratedWindow.hpp"
#include <iostream>
#include <memory>

int main()
{
	std::cout << "*** Start laboratory #1 - Polymorphic resource management ***\n";
	{
		lab1::SessionManager manager{};

		manager.add_window(std::make_unique<lab1::ConsoleWindow>());
		manager.add_window(std::make_unique<lab1::HardwareAcceleratedWindow>());

		manager.render_all();
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