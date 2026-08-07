#include "lab1/TransactionProcessor.hpp"
#include <iostream>

lab1::TransactionProcessor::TransactionProcessor(lab1::FraudFilter filter, lab1::FeeApplier applier) :
	filter_(std::move(filter)), applier_(std::move(applier)) {};

void lab1::TransactionProcessor::add_transaction(std::unique_ptr<lab1::Transaction> transaction)
{
	std::cout << "[TransactionProcessor] Adding a transaction.\n";

	transaction_.push_back(std::move(transaction));
}

void lab1::TransactionProcessor::process_all()
{
	std::cout << "[TransactionProcessor] Processing...\n";

	for (const auto& tranc : transaction_)
	{
		std::cout << "\tobtaining a reference to the current object\n";
		const auto raw_obj{ tranc.get()};
		
		if (raw_obj)
		{
			const bool is_verification_passed{ filter_.check(*raw_obj) };

			if (is_verification_passed)
			{
				applier_.apply(*raw_obj);
			}
			else
			{
				std::cout << "\t\tverification failed!\n";
				tranc->mark_as_fraud();
			}
		}

		std::cout << "---------\n";
	}
}