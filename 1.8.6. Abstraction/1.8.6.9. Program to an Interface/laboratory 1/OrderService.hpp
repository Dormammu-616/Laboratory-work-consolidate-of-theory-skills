#pragma once
#include <laboratory 1/IRepository.hpp>
#include <memory>

class OrderService
{
public:
	OrderService() = delete;
	OrderService(std::shared_ptr<IRepository> service);
	~OrderService() = default;
	void process_new_order(std::string_view order_data);
private:
	std::shared_ptr<IRepository> p_repository;
};