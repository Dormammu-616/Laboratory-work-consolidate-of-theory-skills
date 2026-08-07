#include "lab1/FraudFilter.hpp"
#include <iostream>

lab1::FraudFilter::FraudFilter(double max_limit) : max_allowed_amount_(max_limit) {};

bool lab1::FraudFilter::check(const lab1::Transaction& transaction) const
{
	std::cout << "[FraudFilter] Checking...\n";

	if (transaction.get_amount() > max_allowed_amount_)
	{
		std::cout << "\tTransaction blocked: amount '" << transaction.get_amount() << "' exceeds limit of '" << max_allowed_amount_ << "'.\n";
		return false;
	}

	std::cout << "\tTransaction allowed!\n";
	return true;
}