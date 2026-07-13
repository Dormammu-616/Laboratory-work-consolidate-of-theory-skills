#pragma once
#include "lab3/IEventPayload.hpp"
#include <vector>
#include <memory>

namespace lab3
{
	class EventBus
	{
	public:
		void publish(std::unique_ptr<lab3::IEventPayload> event);
		void process_events();
	private:
		std::vector<std::unique_ptr<lab3::IEventPayload>> event_queue{};
	};
}