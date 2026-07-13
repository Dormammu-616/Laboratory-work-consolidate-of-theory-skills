#include "lab3/EventBus.hpp"
#include <iostream>

void lab3::EventBus::publish(std::unique_ptr<lab3::IEventPayload> event)
{
	event_queue.push_back(std::move(event));
	std::cout << "[EventBus] Event successfully added.\n";
}

void lab3::EventBus::process_events()
{
	std::cout << "[EventBus] Processing events...\n";

	while (!event_queue.empty())
	{
		std::unique_ptr<lab3::IEventPayload> event { std::move(event_queue.back()) };
		event_queue.pop_back();
		std::cout << "\t[EventBus] An event was retrieved from the queue at address '"<< event.get() <<"'.\n";
		std::cout << "-------\n";
	}

	std::cout << "[EventBus] Event processing complete!\n";
}