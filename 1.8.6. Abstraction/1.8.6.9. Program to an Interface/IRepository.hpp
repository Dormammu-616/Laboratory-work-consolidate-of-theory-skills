#pragma once
#include <string>

class IRepository
{
public:
	virtual bool save_order(std::string_view order_data) = 0;
	virtual ~IRepository() = default;
};