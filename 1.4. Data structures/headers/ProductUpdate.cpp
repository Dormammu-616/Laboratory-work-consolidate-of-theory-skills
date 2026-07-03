#include "ProductUpdate.h"

ProductUpdate::ProductUpdate(uint64_t id, double cost) : product_id(id), price(cost) {};

bool ProductUpdate::operator<(const ProductUpdate& other) const
{
	return this->product_id < other.product_id;
}

bool ProductUpdate::operator==(const ProductUpdate& other) const
{
	return this->product_id == other.product_id;
}