#pragma once
#include <iostream>
#include <string_view>

namespace lab3
{
	class CoreApiHandler
	{
	public:
		void handle_request(std::string_view req)
		{
			std::cout << "[CoreApiHandler] Processing request '"<< req <<"'.\n";
		}
		static constexpr bool is_cacheable{ true };
	};
}