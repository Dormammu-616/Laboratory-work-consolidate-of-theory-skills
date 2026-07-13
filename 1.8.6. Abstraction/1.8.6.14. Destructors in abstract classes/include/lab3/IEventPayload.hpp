#pragma once

namespace lab3
{
	class IEventPayload
	{
	public:
		virtual ~IEventPayload() = 0;
	protected:
		IEventPayload() = default;
		IEventPayload(IEventPayload&) = default;
		IEventPayload& operator=(IEventPayload&) = default;
		IEventPayload(IEventPayload&&) = default;
		IEventPayload& operator=(IEventPayload&&) = default;
	};
}