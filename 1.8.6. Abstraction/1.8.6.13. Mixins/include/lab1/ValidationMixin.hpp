#pragma once
#include <iostream>
#include <string_view>
#include <utility>

namespace lab1
{
	template<typename Base> class ValidationMixin : public Base
	{
	public:
		template <typename ... Args>
		ValidationMixin(Args&&... args) : Base(std::forward<Args>(args)...) {}

		void process_packet(std::string_view packet_data)
		{
			std::cout << "[template<ValidationMixin>] Starting assembly...\n";

			if (packet_data.empty() || packet_data.find("ERROR") != std::string_view::npos)
			{
				std::cout << "[template<ValidationMixin>] Error: packet rejected!.\n";
				return;
			}
			Base::process_packet(packet_data);
			std::cout << "[template<ValidationMixin>] End processing...\n";
		}
	};
}