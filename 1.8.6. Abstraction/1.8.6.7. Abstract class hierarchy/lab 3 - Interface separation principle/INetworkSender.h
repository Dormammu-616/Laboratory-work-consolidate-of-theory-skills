#pragma once
#include <string>

class INetwork_Sender
{
public:
	virtual ~INetwork_Sender() = default;
	virtual void send_payload(const std::string& data) = 0;
};