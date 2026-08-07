#include "lab1/FeeApplier.hpp"
#include <iostream>

lab1::FeeApplier::FeeApplier(double rate) : fee_rate_(rate) {};

void lab1::FeeApplier::apply(lab1::Transaction& transaction) const
{
	std::cout << "[FeeApplier] Commission calculation:\n";

	std::cout << "\tbefore: '"<< transaction.get_amount() << "'\n";
	transaction.deduct_fee(fee_rate_);

	std::cout << "\tafter: '" << transaction.get_amount() << "'\n";
}