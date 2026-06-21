#include "include/laboratory 3/OrderCheckout.hpp"
#include <iostream>

BusinessLogic::OrderCheckout::OrderCheckout(std::shared_ptr<IPaymentMethod> method) : m_payment_method(std::move(method)) {};

void BusinessLogic::OrderCheckout::change_payment_method(std::shared_ptr<IPaymentMethod> new_method)
{
	std::cout << "[BusinessLogic::OrderCheckout] Moving the new method...\n";
	m_payment_method = std::move(new_method);
}

void BusinessLogic::OrderCheckout::checkout(const double amount) const
{
	std::cout << "[BusinessLogic::OrderCheckout] Initiating checkout process...\n";

	if (m_payment_method)
	{
		m_payment_method->process_payment(amount);
	}
	else
	{
		std::cout << "[BusinessLogic::OrderCheckout] Error: payment method is not set!.\n";
	}
}