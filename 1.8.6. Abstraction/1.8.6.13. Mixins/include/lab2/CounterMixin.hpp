#pragma once
#include <iostream>

namespace lab2
{
	template <typename Derived> class CounterMixin
	{
	public:
		CounterMixin()	{ ++active_instances; }
		~CounterMixin()	{ --active_instances; }
		static size_t get_active_count()
		{
			return active_instances;
		}
	private:
		inline static size_t active_instances{ 0 };
	};
}