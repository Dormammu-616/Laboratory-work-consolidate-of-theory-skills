#pragma once
#include <cstdint>
#include <iostream>

namespace lab3
{
	struct BoxedGoods
	{
		uint64_t item_id{ 0 };
		double weight{ 0 };

		using category_type = int64_t;
		auto operator<=>(const lab3::BoxedGoods&) const = default;

		category_type get_item_id() const noexcept
		{
			std::cout << "[BoxedGoods] Obtaining the ID ";
			return item_id;
		}

		double get_weight_kg() const
		{
			std::cout << "[BoxedGoods] Obtaining the weight value ";
			return weight;
		}
	};

	struct HeavyMachinery
	{
		uint64_t item_id{ 0 };
		double weight{ 0 };

		using category_type = int64_t;
		auto operator<=>(const lab3::HeavyMachinery&) const = default;

		category_type get_item_id() const // отсутствие noexcept нарушит составное требование
		{
			std::cout << "[HeavyMachinery] Obtaining the ID ";
			return item_id;
		}

		double get_weight_kg() const
		{
			std::cout << "[HeavyMachinery] Obtaining the weight value ";
			return weight;
		}

		int64_t mass[1000]{}; // рарушит вложенное требование (размер типа)
	};
}