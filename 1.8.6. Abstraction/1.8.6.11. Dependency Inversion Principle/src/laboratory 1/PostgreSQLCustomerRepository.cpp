#include "include/laboratory 1/PostgreSQLCustomerRepository.hpp"
#include <iostream>

int64_t Infrastructure::PostgreSQLCustomerRepository::get_credit_score(std::string_view customer_id) const
{
	const int64_t val{ 750 };
	std::cout << "[Infrastructure::PostgreSQLCustomerRepository] Openning connecting to the database. Search rating by ID '" << customer_id << ": " << val << "'.\n";
	return val;
}