#include <laboratory 1/MemoryRepository.hpp>
#include <iostream>

bool MemoryRepository::save_order(std::string_view order_data)
{
	if (order_data.empty())
	{
		std::cout << "[Memory] Connection failed. No data to save.\n";
		return false;
	}

	std::cout << "[Memory] The order '" << order_data << "' has been successfully saved in RAM!\n";
	return true;
}