#pragma once
#include "lab2/SecurityPolicy.hpp"

namespace lab2
{
	class DatabaseConnection : public lab2::SecurityPolicy
	{
	public:
		DatabaseConnection();
		~DatabaseConnection();
		void execute_query() const;
	};
}