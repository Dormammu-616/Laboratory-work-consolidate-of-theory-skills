#pragma once
#include "AbstractWiFiSender.h"

class Open_WiFi_Sender : public Abstract_WiFi_Sender
{
public:
	Open_WiFi_Sender(const std::string& ip);
	~Open_WiFi_Sender() override = default;
	void send_payload(const std::string& data) override;
};