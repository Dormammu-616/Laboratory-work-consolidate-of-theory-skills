#include <laboratory 1/OrderService.hpp>
#include <iostream>

OrderService::OrderService(std::shared_ptr<IRepository> service) : p_repository(std::move(service)) { std::cout << "\n"; };

void OrderService::process_new_order(std::string_view order_data)
{
	if (order_data.empty())
	{
		std::cout << "[OrderService] The order is empty!\n";
		return;
	}

	std::cout << "[OrderService] Checking order '" << order_data << "'.\n";
	p_repository->save_order(order_data);
};