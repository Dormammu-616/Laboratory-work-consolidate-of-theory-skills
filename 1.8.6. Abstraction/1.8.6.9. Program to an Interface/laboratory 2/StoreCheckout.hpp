#pragma once
#include <laboratory 2/IPaymentProcessor.hpp>
#include <memory>

class StoreCheckout
{
public:
	StoreCheckout() = delete;
	StoreCheckout(std::shared_ptr<IPaymentProcessor> payment);
	void checkout_cart(const double total);
	~StoreCheckout() = default;
private:
	std::shared_ptr<IPaymentProcessor> m_payment;
};