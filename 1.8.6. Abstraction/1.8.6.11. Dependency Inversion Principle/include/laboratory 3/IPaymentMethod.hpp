#pragma once

namespace BusinessLogic
{
	class IPaymentMethod
	{
	public:
		virtual ~IPaymentMethod() = default;
		virtual void process_payment(const double amount) const = 0;
	};
}