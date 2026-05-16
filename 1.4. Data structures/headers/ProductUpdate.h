#pragma once
#include <cstdint>

struct ProductUpdate
{
	uint64_t product_id{};
	double price{};
	ProductUpdate(uint64_t id, double cost);
	bool operator<(const ProductUpdate& other) const;
	bool operator==(const ProductUpdate& other) const;
};