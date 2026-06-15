#include "include/laboratory 1/AdvancedMFP.hpp"
#include <iostream>

AdvancedMFP::AdvancedMFP(std::string_view name) : device_name(name) {};

void AdvancedMFP::print_document(std::string_view text)
{
	std::cout << "[AdvancedMFP] Printing a document with text:\n\t" << text << "\n";
}

std::string AdvancedMFP::scan_document() const
{
	std::cout << "[AdvancedMFP] Scanning document...\n";
	return "Dummy scanned document content";
}

void AdvancedMFP::send_fax(std::string_view text, std::string_view number)
{
	std::cout << "[AdvancedMFP] From the current device '" << device_name << "' sends a text to the number '"<<number << "':\n\t" << text << "\n";
}
