#pragma once
#include "include/laboratory 1/ICustomerRepository.hpp"
#include <memory>
#include <string_view>

namespace BusinessLogic
{
	class LoanCalculator
	{
	public:
		explicit LoanCalculator(std::shared_ptr<ICustomerRepository> repository);
		~LoanCalculator() = default;
		void assess_loan_application(std::string_view customer_id) const;
	private:
		std::shared_ptr<ICustomerRepository> m_repository;
	};
}