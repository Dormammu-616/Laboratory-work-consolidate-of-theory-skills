#pragma once
#include <laboratory 1/IRepository.hpp>

class MySQLRepository : public IRepository
{
public:
	MySQLRepository() = default;
	~MySQLRepository() = default;
	bool save_order(std::string_view order_data) override;
};