#include <laboratory 2/StoreCheckout.hpp>
#include <iostream>

StoreCheckout::StoreCheckout(std::shared_ptr<IPaymentProcessor> payment) : m_payment(std::move(payment)) {};

void StoreCheckout::checkout_cart(const double total)
{
	std::cout << "[StoreCheckout] Cart payment...\n";
	const bool IS_SUCCESSFUL_PAYMENT{ m_payment->process_payment(total) };
	
	std::cout << std::boolalpha << "[StoreCheckout] Status payment: '" << IS_SUCCESSFUL_PAYMENT << "'.\n" << std::noboolalpha;
}