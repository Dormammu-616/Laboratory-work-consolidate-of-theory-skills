#pragma once
#include <laboratory 1/IRepository.hpp>

class MemoryRepository : public IRepository
{
public:
	MemoryRepository() = default;
	~MemoryRepository() = default;
	bool save_order(std::string_view order_data) override;
};