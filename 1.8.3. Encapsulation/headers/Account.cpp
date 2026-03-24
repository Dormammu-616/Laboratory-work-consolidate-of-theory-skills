#include <stdexcept>
#include "Account.h"

Account::Account(const std::string& owner_name, const size_t start_score) : name(owner_name), score(start_score)
{
	if (owner_name == "") throw std::invalid_argument("name must not be empty!.\n");
};

bool Account::deposit(const size_t amount)
{
	if (account_active)
	{
		score += amount;
		return true;
	}

	return false;
}

bool Account::withdraw(const size_t amount)
{
	if (!account_active || score < amount)
	{
		return false;
	}

	score -= amount;
	return true;
	
}

bool Account::deactivate()
{
	if (account_active)
	{
		account_active = false;
		return true;
	}

	return false;
}

bool Account::activate()
{
	if (!account_active)
	{
		account_active = true;
		return true;
	}

	return false;
}
