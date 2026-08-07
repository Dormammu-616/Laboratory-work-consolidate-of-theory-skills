#pragma once
#include <string>

namespace lab1
{
	class Transaction
	{
	public:
		Transaction(std::string_view id, const double amount);
		Transaction(const Transaction&) = delete;
		Transaction& operator=(const Transaction&) = delete;
		~Transaction() = default;
		[[nodiscard]] std::string_view get_id() const;
		double get_amount() const;
		bool is_valid() const;
		void mark_as_fraud();
		void deduct_fee(double fee);
	private:
		std::string id_{""};
		double amount_{0.0};
		bool is_valid_{ true };
	};
}