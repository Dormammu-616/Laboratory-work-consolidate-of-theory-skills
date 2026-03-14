#pragma once
#include "INetworkSender.h"
#include <memory>

class Network_Sender_Factory
{
public:
	Network_Sender_Factory() = default;
	~Network_Sender_Factory() = default;
	static std::unique_ptr<INetwork_Sender> create_sender(const std::string& type, const std::string& ip);
};