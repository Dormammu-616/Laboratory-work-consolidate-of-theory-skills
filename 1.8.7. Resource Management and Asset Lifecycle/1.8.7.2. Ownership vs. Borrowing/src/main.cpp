#include "lab1/TransactionProcessor.hpp"
#include <iostream>

int main()
{
	std::cout << "*** Start laboratory #1 - Strict Contracts: Observers and Mutators ***\n";
	{
		lab1::FraudFilter filter{ 10.5 };
		lab1::FeeApplier applier{ 1.5 };
		lab1::TransactionProcessor processor{ filter, applier };

		processor.add_transaction(std::make_unique<lab1::Transaction>("ex01", 1.01));
		processor.add_transaction(std::make_unique<lab1::Transaction>("ex02", 4.11));
		processor.add_transaction(std::make_unique<lab1::Transaction>("ex03", 64.43));

		processor.process_all();
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 -  ***\n";
	{

	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{

	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}