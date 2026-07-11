#include "lab1/ConsoleWindow.hpp"
#include <iostream>

lab1::ConsoleWindow::ConsoleWindow()
{
	buffer.push_back('a');
	buffer.push_back('b');
	buffer.push_back('c');
	buffer.push_back('d');

	std::cout << "[ConsoleWindow] Allocation of '"<< buffer.size() << "' bytes for text buffer.\n";
}

void lab1::ConsoleWindow::render() const
{
	std::cout << "\t[ConsoleWindow] Contained in the buffer: ";

	for (const auto& elem : buffer)
	{
		std::cout << "''" << elem << "' ";
	}
	std::cout << "\n";
}

lab1::ConsoleWindow::~ConsoleWindow()
{
	buffer.clear();
	buffer.shrink_to_fit();
	std::cout << "[ConsoleWindow] Freeing text buffer with a size of '" << buffer.size() <<"'.\n";
}
