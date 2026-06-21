#include "include/laboratory 2/TwilioNotifierAdapter.hpp"
#include <iostream>

Infrastructure::TwilioNotifierAdapter::TwilioNotifierAdapter(std::shared_ptr<ExternalVendor::TwilioApi> api, std::string phone_number)
	: p_api(std::move(api)), number(std::move(phone_number)) {}

void Infrastructure::TwilioNotifierAdapter::send_notification(std::string_view message) const
{
	std::cout << "[Infrastructure::TwilioNotifierAdapter] Sending...\n";

	p_api->send_sms(number, message);
}