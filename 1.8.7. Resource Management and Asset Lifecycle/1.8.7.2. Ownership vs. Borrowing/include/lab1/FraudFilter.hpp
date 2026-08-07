#pragma once
#include "lab1/Transaction.hpp"

namespace lab1
{
	class FraudFilter
	{
	public:
		FraudFilter(double max_limit);
		~FraudFilter() = default;
		bool check(const lab1::Transaction& transaction) const;
	private:
		double max_allowed_amount_{ 10000.0 };
	};
}