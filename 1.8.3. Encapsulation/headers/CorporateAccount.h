#pragma once
#include "Account.h"

class CorparateAccount : public Account
{
public:
	CorparateAccount() = delete;
	CorparateAccount(const std::string& owner_name, const size_t start_score, const size_t start_bonus);
	bool apply_bonus_account();
};