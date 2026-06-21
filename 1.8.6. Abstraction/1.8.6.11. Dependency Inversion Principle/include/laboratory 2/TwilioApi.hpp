#pragma once
#include <string_view>

namespace ExternalVendor
{
	class TwilioApi
	{
	public:
		TwilioApi() = default;
		~TwilioApi() = default;
		void send_sms(std::string_view phone_number, std::string_view text) const;
	};
}