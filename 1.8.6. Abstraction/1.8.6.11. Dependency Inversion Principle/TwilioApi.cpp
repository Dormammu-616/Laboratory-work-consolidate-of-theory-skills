#include "include/laboratory 2/TwilioApi.hpp"
#include <iostream>

void ExternalVendor::TwilioApi::send_sms(std::string_view phone_number, std::string_view text) const
{
	std::cout << "[ExternalVendor::TwilioApi] Sending SMS to '"<< phone_number << "': "<< text << ".\n";
}