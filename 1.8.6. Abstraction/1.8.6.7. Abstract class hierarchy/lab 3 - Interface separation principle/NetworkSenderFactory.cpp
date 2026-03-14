#include "NetworkSenderFactory.h"
#include "SecureWiFiSender.h"
#include "OpenWiFiSender.h"

std::unique_ptr<INetwork_Sender> Network_Sender_Factory::create_sender(const std::string& type, const std::string& ip)
{
	if (type == "secure")
	{
		return std::make_unique<Secure_WiFi_Sender>(ip);
	}
	else if (type == "open")
	{
		return std::make_unique<Open_WiFi_Sender>(ip);
	}

	return nullptr;
}