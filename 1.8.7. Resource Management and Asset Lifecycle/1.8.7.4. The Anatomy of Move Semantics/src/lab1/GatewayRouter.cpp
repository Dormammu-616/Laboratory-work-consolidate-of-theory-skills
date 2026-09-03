#include "lab1/GatewayRouter.hpp"
#include <iostream>

void lab1::GatewayRouter::set_payload(lab1::CryptoBuffer payload)
{
	std::cout << "[GatewayRouter] Setting payload.\n";

	internal_buffer_ = std::move(payload);
}