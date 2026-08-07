#pragma once
#include "lab1/Transaction.hpp"

namespace lab1
{
	class FeeApplier
	{
	public:
		FeeApplier(double rate);
		~FeeApplier() = default;
		void apply(lab1::Transaction& transaction) const;
	private:
		double fee_rate_{ 0.05 }; // коммисия 5%
	};
}