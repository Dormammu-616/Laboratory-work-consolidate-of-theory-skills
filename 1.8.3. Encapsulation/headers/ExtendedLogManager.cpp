#include "ExtendedLogManager.h"
#include <iostream>

void ExtendedLogManager::print_last_type() const
{
	std::cout << "Last type: " << last_type_log() << ".\n";
}