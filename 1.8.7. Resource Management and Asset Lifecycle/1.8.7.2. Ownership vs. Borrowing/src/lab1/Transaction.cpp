#include "lab1/Transaction.hpp"
#include <iostream>

lab1::Transaction::Transaction(std::string_view id, const double amount) : id_(id), amount_(amount) {}

std::string_view  lab1::Transaction::get_id() const
{
	return id_;
}

double lab1::Transaction::get_amount() const
{
	return amount_;
}

bool lab1::Transaction::is_valid() const
{
	return is_valid_;
}

void lab1::Transaction::mark_as_fraud()
{
	std::cout << "[Transaction] Mark as fraud.\n";
	is_valid_ = false;
}

void lab1::Transaction::deduct_fee(double fee)
{
	std::cout << "[Transaction] Deduct fee '"<< fee << "'.\n";
	amount_ -= fee;
}