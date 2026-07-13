#include "lab2/DatabaseConnection.hpp"
#include <iostream>

lab2::DatabaseConnection::DatabaseConnection()
{
	std::cout << "[DatabaseConnection] Constructor: connected to PostgreSQL.\n";
}

lab2::DatabaseConnection::~DatabaseConnection()
{
	std::cout << "[DatabaseConnection] Destructor: connection to PostgreSQL closed.\n";
}

void lab2::DatabaseConnection::execute_query() const
{
	std::cout << "[DatabaseConnection] Executing a request to a PostgreSQL...\n";
}