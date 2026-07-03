#pragma once
#include <string>

class Account
{
public:
	Account() = delete;
	Account(const std::string& owner_name, const size_t start_score);
	bool deposit(const size_t amount);
	bool withdraw(const size_t amount);
	bool deactivate();
	bool activate();
protected:
	size_t start_bonus{0};
private:
	const std::string name;			// имя
	size_t score{ 0 };				// счет
	bool account_active{ true };	// состояние счета
};