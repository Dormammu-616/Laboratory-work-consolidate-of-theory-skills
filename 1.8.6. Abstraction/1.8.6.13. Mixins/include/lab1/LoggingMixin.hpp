#pragma once
#include <iostream>
#include <string_view>
#include <utility>

namespace lab1
{
	template<typename Base> class LoggingMixin : public Base
	{
	public:
		template <typename ... Args>
		LoggingMixin(Args&&... args) : Base(std::forward<Args>(args)...) {}

		void process_packet(std::string_view packet_data)
		{
			std::cout << "[template<LoggingMixin>] Starting assembly...\n";
			Base::process_packet(packet_data);
			std::cout << "[template<LoggingMixin>] End processing...\n";
		}
	};
}