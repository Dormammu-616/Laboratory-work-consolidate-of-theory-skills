#include "SecureWiFiSender.h"
#include <iostream>

Secure_WiFi_Sender::Secure_WiFi_Sender(const std::string& ip) : Abstract_WiFi_Sender{ ip } {};

void Secure_WiFi_Sender::send_payload(const std::string& data)
{
	std::cout << "\t[Secure -> " << ip_address << "] Encrypting and sending: "<< data << ".";
}