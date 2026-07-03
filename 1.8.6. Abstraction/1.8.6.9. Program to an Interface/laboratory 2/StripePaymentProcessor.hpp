#pragma once
#include <laboratory 2/IPaymentProcessor.hpp>

class StripePaymentProcessor : public IPaymentProcessor
{
public:
	StripePaymentProcessor() = default;
	~StripePaymentProcessor() = default;
	bool process_payment(const double amount) override;
};