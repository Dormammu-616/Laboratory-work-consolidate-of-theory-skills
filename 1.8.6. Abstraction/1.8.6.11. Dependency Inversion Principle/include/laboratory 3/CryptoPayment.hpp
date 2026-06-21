#pragma once
#include "include/laboratory 3/IPaymentMethod.hpp"

namespace PaymentGateways
{
	class CryptoPayment : public BusinessLogic::IPaymentMethod
	{
	public:
		~CryptoPayment() override = default;
		void process_payment(const double amount) const override;
	};
}