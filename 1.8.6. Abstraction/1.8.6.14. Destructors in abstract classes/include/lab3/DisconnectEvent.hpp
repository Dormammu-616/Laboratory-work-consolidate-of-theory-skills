#pragma once
#include "lab3/IEventPayload.hpp"

namespace lab3
{
	class DisconnectEvent : public lab3::IEventPayload
	{
	public:
		DisconnectEvent(int socket);
		~DisconnectEvent() override;
	private:
		int socket_id{0};
	};
}