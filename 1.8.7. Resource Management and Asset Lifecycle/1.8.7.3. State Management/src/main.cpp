#include "lab1/RawNetworkBuffer.hpp"
#include <iostream>

int main()
{
	std::cout << "*** Start laboratory #1 - The Rule of Three and the shallow copy problem ***\n";
	{
		lab1::RawNetworkBuffer buffer{ 10 };
		
		std::cout << "\nDemonstration of the copy constructor:\n";
		lab1::RawNetworkBuffer buffer_for_copy_constructor{buffer};

		std::cout << "\nDemonstration of the assignment operator:\n";
		lab1::RawNetworkBuffer buffer_for_assignment_oper{5};
		buffer_for_assignment_oper = buffer;

		std::cout << "\nDemonstration of self-assignment:\n";
		buffer_for_assignment_oper = buffer_for_assignment_oper;
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