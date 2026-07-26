#pragma once
#include "lab3/BusinessConcepts.hpp"
#include <iostream>

namespace lab3
{
	class WarehouseProcessor
	{
	public:
		template <lab3::ValidWarehouseItem T> void process_item(const T& item)
		{
			std::cout << "[WarehouseProcessor] Item accepted:\n"
				<< "\tID: " << item.get_item_id() << "\n"
				<< "\tweight: "<< item.get_weight_kg() << "\n";
		}
	};
}