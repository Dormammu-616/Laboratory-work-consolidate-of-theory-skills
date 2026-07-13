#pragma once
#include "lab3/IEventPayload.hpp"
#include <string>

namespace lab3
{
	class TimeoutEvent : public lab3::IEventPayload
	{
	public:
		TimeoutEvent(const std::string& name);
		~TimeoutEvent() override;
	private:
		std::string process_name{};
	};
}