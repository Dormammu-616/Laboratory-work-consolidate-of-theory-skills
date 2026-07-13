#include "lab2/NetworkConnection.hpp"
#include <iostream>

lab2::NetworkConnection::NetworkConnection()
{
	std::cout << "[NetworkConnection] Constructor: port 8080 opened.\n";
}

lab2::NetworkConnection::~NetworkConnection()
{
	std::cout << "[NetworkConnection] Destructor: port 8080 closed.\n";
}

void lab2::NetworkConnection::connect() const
{
	std::cout << "[NetworkConnection] Connecting to port...\n";
}