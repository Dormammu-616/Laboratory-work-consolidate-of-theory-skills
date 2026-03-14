#pragma once
#include "INetworkSender.h"

class Abstract_WiFi_Sender : public INetwork_Sender
{
public:
	Abstract_WiFi_Sender(const std::string& ip) : ip_address(ip) {};
	~Abstract_WiFi_Sender() override = default;
protected:
	std::string ip_address{};
};
