#pragma once
#include <string_view>

namespace BusinessLogic
{
	class INotifier
	{
	public:
		virtual ~INotifier() = default;
		virtual void send_notification(std::string_view message) const = 0;
	};
}
