#pragma once
#include "lab1/CryptoBuffer.hpp"

namespace lab1
{
	class GatewayRouter
	{
	public:
		void set_payload(lab1::CryptoBuffer payload);
	private:
		lab1::CryptoBuffer internal_buffer_{ 0 };
	};
}