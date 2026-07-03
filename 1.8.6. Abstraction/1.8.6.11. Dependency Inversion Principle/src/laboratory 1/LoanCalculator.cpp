#include "include/laboratory 1/LoanCalculator.hpp"
#include <iostream>

BusinessLogic::LoanCalculator::LoanCalculator(std::shared_ptr<ICustomerRepository> repository) : m_repository(std::move(repository)) {}

void BusinessLogic::LoanCalculator::assess_loan_application(std::string_view customer_id) const
{
	const int64_t score{ m_repository->get_credit_score(customer_id) };

	if (score > 600)
	{
		std::cout << "[BusinessLogic::LoanCalculator] Rating: '"<< score << "'. Credit approved!\n";
	}
	else
	{
		std::cout << "[BusinessLogic::LoanCalculator] Rating: '" << score << "'. Credit denied!\n";
	}
}
