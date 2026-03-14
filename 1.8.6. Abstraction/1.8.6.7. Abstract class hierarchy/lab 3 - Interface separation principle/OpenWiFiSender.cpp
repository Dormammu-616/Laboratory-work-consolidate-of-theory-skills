#include "OpenWiFiSender.h"
#include <iostream>

Open_WiFi_Sender::Open_WiFi_Sender(const std::string& ip) : Abstract_WiFi_Sender{ ip } {};

void Open_WiFi_Sender::send_payload(const std::string& data)
{
	std::cout << "\t[Open wifi -> " << ip_address << "] Encrypting and sending: " << data << ".";
}