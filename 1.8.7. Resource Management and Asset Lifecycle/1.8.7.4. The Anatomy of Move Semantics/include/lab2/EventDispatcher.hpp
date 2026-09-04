#pragma once
#include "lab2/SecurityEvent.hpp"
#include <vector>
#include <iostream>
#include <utility>

namespace lab2
{
	class EventDispatcher
	{
	public:
		template <typename T> void dispatch(T&& event)
		{
			//event_queue_.emplace_back(event); // ОШИБКА: приведет к КОПИРОВАНИЮ данных!
			//event_queue_.emplace_back(std::move(event)); // ОШИБКА: приведет к ПЕРЕМЕЩЕНИЮ данных!
			
			event_queue_.emplace_back(std::forward<T>(event));
			std::cout << "[EventDispatcher] The routing method has been called.\n";
		}
	private:
		std::vector<lab2::SecurityEvent> event_queue_{};
	};
}