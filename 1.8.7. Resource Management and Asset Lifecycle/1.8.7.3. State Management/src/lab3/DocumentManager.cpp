#include "lab3/DocumentManager.hpp"
#include <iostream>

lab3::DocumentManager::DocumentManager(const std::string& title, size_t size_content) : title_(title), content_(size_content, static_cast<uint8_t>(0))
{
	std::cout << "[DocumentManager] Called user-defined constructor with name '"<< title << "' and size '"<< size_content << "'.\n\n";
}

void lab3::DocumentManager::print_info() const
{
	std::cout << "[DocumentManager] Info about object:\n"
		<< "\ttitle:\t\t" << title_ << "\n"
		<< "\tsize:\t\t" << content_.size() << "\n"
		<< "\taddress:\t" << static_cast<const void*>(content_.data()) << "\n\n";
}