#include "lab2/SignatureScanner.hpp"
#include <iostream>

bool lab2::SignatureScanner::is_contains(std::string_view data, std::string_view pattern) const
{
	if (data.find(pattern) != std::string_view::npos)
	{
		return true;
	}

	return false;
}

void lab2::SignatureScanner::print_hex_dump(std::string_view data) const
{
	std::cout << "[SignatureScanner] Print hex dump.\n"
		<< "\tsize: '" << data.size() << "'\n"
		<< "\thex: '";

	for (const auto& c : data)
	{
		std::cout << c;
	}
	std::cout << "'\n";
}