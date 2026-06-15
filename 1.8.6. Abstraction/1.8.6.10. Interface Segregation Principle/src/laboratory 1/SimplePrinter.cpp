#include "include/laboratory 1/SimplePrinter.hpp"
#include <iostream>

void SimplePrinter::print_document(std::string_view text)
{
	std::cout << "[SimplePrinter] Printing a document with text:\n\t" << text << "\n";
	++printed_pages_count;
	std::cout << "[SimplePrinter] The current printed pages count = '"<< printed_pages_count <<"'\n";
}