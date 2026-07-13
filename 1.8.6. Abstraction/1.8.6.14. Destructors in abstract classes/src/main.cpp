#include "lab1/SessionManager.hpp"
#include "lab1/ConsoleWindow.hpp"
#include "lab1/HardwareAcceleratedWindow.hpp"
#include "lab2/ConnectionPool.hpp"
#include "lab2/NetworkConnection.hpp"
#include "lab2/DatabaseConnection.hpp"
#include "lab3/EventBus.hpp"
#include "lab3/DisconnectEvent.hpp"
#include "lab3/TimeoutEvent.hpp"
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

	std::cout << "*** Start laboratory #2 - Protected destructor and type erasure ***\n";
	{
		lab2::ConnectionPool pool{};

		pool.add_policy(std::make_shared<lab2::NetworkConnection>());
		pool.add_policy(std::make_shared<lab2::DatabaseConnection>());
		pool.verify_all();

		// Архитектурный тест (Compile-time error):
		//std::unique_ptr<lab2::SecurityPolicy> ptr_policy{ std::make_unique<lab2::NetworkConnection>() };
		// ошибка компилятор: std::unique_ptr использует статическое связывание и пытается вызвать delete для указателя типа SecurityPolicy.
		// Так как деструктор SecurityPolicy объявлен как protected, внешний код (включая default_delete) не имеет к нему доступа. Это предотвращает UB.
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 - Pure virtual destructor ***\n";
	{
		lab3::EventBus event_bus{};

		event_bus.publish(std::make_unique<lab3::DisconnectEvent>(404));
		event_bus.publish(std::make_unique<lab3::TimeoutEvent>("RenderThread"));

		event_bus.process_events();
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}