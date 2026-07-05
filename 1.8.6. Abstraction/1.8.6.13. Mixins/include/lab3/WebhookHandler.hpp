#pragma once
#include <iostream>
#include <string_view>

namespace lab3
{
	class WebhookHandler
	{
	public:
		void handle_request(std::string_view req)
		{
			std::cout << "[WebhookHandler] Rapid event processing '" << req << "'.\n";
		}
		static constexpr bool is_cacheable{ false };
	};
}