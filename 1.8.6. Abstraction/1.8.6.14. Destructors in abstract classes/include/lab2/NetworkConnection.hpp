#pragma once
#include "lab2/SecurityPolicy.hpp"

namespace lab2
{
	class NetworkConnection : public lab2::SecurityPolicy
	{
	public:
		NetworkConnection();
		~NetworkConnection();
		void connect() const;
	};
}