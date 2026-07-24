#pragma once
#include <string>
#include <iostream>

namespace lab1
{
	struct TransactionRecord
	{
		double amount{0.0};
		std::string currency{"$"};
		std::string serialize() const
		{
			std::cout << "\t[TransactionRecord] Contains: amount '" << amount << "', currency '" << currency << "'.\n";
			return currency;
		}
	};
}