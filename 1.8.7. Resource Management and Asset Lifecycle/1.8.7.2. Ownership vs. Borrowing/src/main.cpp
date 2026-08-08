#include "lab1/TransactionProcessor.hpp"
#include "lab2/SignatureScanner.hpp"
#include "lab2/Packet.hpp"
#include "lab2/PacketAnalyzer.hpp"
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

	std::cout << "*** Start laboratory #2 - Zero-Overhead Borrowing ***\n";
	{
		lab2::SignatureScanner scanner{};
		lab2::PacketAnalyzer analyser{ scanner };
		lab2::Packet packet{ 78, "HEADER:AUTH_KEY_999;BODY:DROP TABLE users;END" };

		std::cout << "--- Launch with a contain signature ---\n";
		analyser.analyze(packet, "BODY");
		
		std::cout << "\n--- Launch with a not contain signature ---\n";
		analyser.analyze(packet, "NOTVALUE");
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{

	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}