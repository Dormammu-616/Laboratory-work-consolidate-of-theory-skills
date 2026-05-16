#pragma once
#include <cstdint>

enum class ProductAttribute : uint8_t
{
	Price,
	Stock_count,
	Status
};

struct RollbackAction
{
	uint64_t product_id{};
	ProductAttribute field_name{};
	uint8_t padding[7]{};
	int64_t old_value{};
	int64_t new_value{};
	RollbackAction(const uint64_t id, const ProductAttribute& name_changed_field, int64_t old_num, int64_t new_num) : product_id(id), field_name(name_changed_field), old_value(old_num), new_value(new_num) {};
};