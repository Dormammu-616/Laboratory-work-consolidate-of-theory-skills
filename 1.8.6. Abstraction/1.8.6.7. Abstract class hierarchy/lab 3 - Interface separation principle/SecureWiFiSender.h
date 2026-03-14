#pragma once
#include "AbstractWiFiSender.h"

class Secure_WiFi_Sender : public Abstract_WiFi_Sender
{
public:
	Secure_WiFi_Sender(const std::string& ip);
	~Secure_WiFi_Sender() override = default;
	void send_payload(const std::string& data) override;
};