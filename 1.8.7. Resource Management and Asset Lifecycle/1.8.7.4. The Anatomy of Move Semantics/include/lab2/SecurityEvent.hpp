#pragma once
#include <cstdint>
#include <string>
#include <utility>

namespace lab2
{
	class SecurityEvent
	{
	public:
		SecurityEvent(int64_t id, std::string_view payload);
		SecurityEvent(const SecurityEvent& other);
		SecurityEvent(SecurityEvent&& other) noexcept;
	private:
		int64_t event_id_{ 0 };
		std::string payload_{ "" };
	};
}