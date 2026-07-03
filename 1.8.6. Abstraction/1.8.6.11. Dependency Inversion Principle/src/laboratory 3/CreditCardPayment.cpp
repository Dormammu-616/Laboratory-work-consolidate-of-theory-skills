#include "include/laboratory 3/CreditCardPayment.hpp"
#include <iostream>

void PaymentGateways::CreditCardPayment::process_payment(const double amount) const
{
	std::cout << "[PaymentGateways::CreditCardPayment] Processing credit card payment: $"<< amount <<".\n";
}
