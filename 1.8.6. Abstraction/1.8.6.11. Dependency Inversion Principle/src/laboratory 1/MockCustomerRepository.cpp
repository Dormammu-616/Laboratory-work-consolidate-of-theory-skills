#include "include/laboratory 1/MockCustomerRepository.hpp"
#include <iostream>

int64_t Infrastructure::MockCustomerRepository::get_credit_score(std::string_view customer_id) const
{
	const int64_t val{ 400 };
	std::cout << "[Infrastructure::MockCustomerRepository] Reading rating from cache memory by ID '" << customer_id << ": " << val << "'.\n";
	return val;
}