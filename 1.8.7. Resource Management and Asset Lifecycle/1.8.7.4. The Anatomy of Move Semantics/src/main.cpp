#include <iostream>
#include "lab1/CryptoBuffer.hpp"
#include "lab1/GatewayRouter.hpp"

int main()
{
	std::cout << "*** Start laboratory #1 - Safe Resource Absorption ***\n";
	{
		std::cout << "--- Creating original buffer ---\n";
		lab1::CryptoBuffer buffer_original{ 1024 };
		buffer_original.get_memory_address();

		std::cout << "\n--- Creating copy buffer ---\n";
		lab1::CryptoBuffer buffer_copy{ buffer_original };
		buffer_copy.get_memory_address();

		std::cout << "\n--- Move copy buffer ---\n";
		lab1::GatewayRouter router{};
		router.set_payload(std::move(buffer_copy));

		std::cout << "\n--- Buffer copy after moved ---\n";
		buffer_copy.get_memory_address();
		std::cout << "\n";
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