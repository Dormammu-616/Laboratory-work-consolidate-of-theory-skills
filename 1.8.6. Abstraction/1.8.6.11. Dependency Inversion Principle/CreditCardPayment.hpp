#pragma once
#include "include/laboratory 3/IPaymentMethod.hpp"

namespace PaymentGateways
{
	class CreditCardPayment : public BusinessLogic::IPaymentMethod
	{
	public:
		~CreditCardPayment() override = default;
		void process_payment(const double amount) const override;
	};
}