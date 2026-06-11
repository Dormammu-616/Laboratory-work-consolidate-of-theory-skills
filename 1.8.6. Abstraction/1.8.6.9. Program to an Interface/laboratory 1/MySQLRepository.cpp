#include <laboratory 1/MySQLRepository.hpp>
#include <iostream>

bool MySQLRepository::save_order(std::string_view order_data)
{
	if (order_data.empty())
	{
		std::cout << "[MySQL] Connection failed. No data to save.\n";
		return false;
	}

	std::cout << "[MySQL] Connecting to a database. The order '" << order_data << "' saved successfully!\n";
	return true;
}