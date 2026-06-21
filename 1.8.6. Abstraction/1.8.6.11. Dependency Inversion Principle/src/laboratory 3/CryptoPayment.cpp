#include "include/laboratory 3/CryptoPayment.hpp"
#include <iostream>

void PaymentGateways::CryptoPayment::process_payment(const double amount) const
{
	std::cout << "[PaymentGateways::CryptoPayment] Processing cryptocurrency payment payment: $"<< amount << ".\n";
}