#include "Lab3/NetworkProcessor.hpp"
#include <iostream>

void NetworkProcessor::process_request()
{
	std::cout << "[NetworkProcessor] Opening connection...\n";

	handle_payload();

	std::cout << "[NetworkProcessor] Closing connection.\n\n";
}