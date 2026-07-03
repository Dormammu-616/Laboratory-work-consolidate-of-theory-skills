#include <laboratory 2/StripePaymentProcessor.hpp>
#include <iostream>

bool StripePaymentProcessor::process_payment(const double amount)
{
	if (amount < 0)
	{
		std::cout << "[Stripe] Error: transaction cannot be negative!\n";
		return false;
	}
	std::cout << "[Stripe] Successful transaction for the amount of '"<< amount << "$.'\n";
	return true;
}