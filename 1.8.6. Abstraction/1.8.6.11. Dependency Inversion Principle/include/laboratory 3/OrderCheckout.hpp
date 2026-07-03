#pragma once
#include "include/laboratory 3/IPaymentMethod.hpp"
#include <memory>

namespace BusinessLogic
{
	class OrderCheckout
	{
	public:
		explicit OrderCheckout(std::shared_ptr<IPaymentMethod> method);
		void change_payment_method(std::shared_ptr<IPaymentMethod> new_method);
		void checkout(const double amount) const;
		~OrderCheckout() = default;
	private:
		std::shared_ptr<IPaymentMethod> m_payment_method;
	};
}