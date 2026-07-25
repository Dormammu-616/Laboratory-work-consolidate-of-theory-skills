#pragma once
#include <cstdint>

namespace lab2
{
	class JobDispatcher
	{
	public:
		template <typename Action>
		requires std::invocable<Action, int64_t>
		static void execute_callback(int64_t data, Action action)
		{
			std::cout << "[execute_callback] The 'Action' object received the data '"<< data << "'.\n"
				<< "Call to 'action':\n";
			action(data);
		}
	};
}