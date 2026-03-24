#include "CorporateAccount.h"

CorparateAccount::CorparateAccount(const std::string& owner_name, const size_t start_score, const size_t bonus) : Account(owner_name, start_score)
{
	start_bonus = bonus;
}

bool CorparateAccount::apply_bonus_account()
{
	return deposit(start_bonus);
}