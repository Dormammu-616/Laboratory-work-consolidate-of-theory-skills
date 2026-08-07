#pragma once
#include "lab1/Transaction.hpp"
#include "lab1/FraudFilter.hpp"
#include "lab1/FeeApplier.hpp"
#include <memory>
#include <vector>

namespace lab1
{
	class TransactionProcessor
	{
	public:
		TransactionProcessor(lab1::FraudFilter filter, lab1::FeeApplier applier);
		~TransactionProcessor() = default;
		void add_transaction(std::unique_ptr<lab1::Transaction> transaction);
		void process_all();
	private:
		std::vector<std::unique_ptr<lab1::Transaction>> transaction_;
		lab1::FraudFilter filter_;
		lab1::FeeApplier applier_;
	};
}