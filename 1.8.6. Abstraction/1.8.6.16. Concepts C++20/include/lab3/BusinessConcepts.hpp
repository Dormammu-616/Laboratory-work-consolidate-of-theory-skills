#pragma once
#include <concepts>
#include <cstdint>

namespace lab3
{
	template <typename T>
	concept ValidWarehouseItem = std::regular<T> && requires (const T& data)
	{
		requires sizeof(T) <= 128;
		typename T::category_type;
		{ data.get_item_id() } noexcept -> std::convertible_to<uint64_t>;
		data.get_weight_kg();
	};
}