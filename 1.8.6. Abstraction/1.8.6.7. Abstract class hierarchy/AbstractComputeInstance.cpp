#include <iostream>
#include "AbstractComputeInstance.h"

void AbstractComputeInstance::start()
{
	std::cout << "Sending ACPI start signal.\n";
}

void AbstractComputeInstance::stop()	
{
	std::cout << "Sending ACPI stop signal.\n";
}