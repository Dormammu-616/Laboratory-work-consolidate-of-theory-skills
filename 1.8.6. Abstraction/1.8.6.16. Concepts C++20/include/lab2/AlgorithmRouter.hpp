#pragma once
#include <iterator>
#include <iostream>

namespace lab2
{
	template <typename Iterator>
	requires std::forward_iterator<Iterator>
	void advance_cursor(Iterator& it, size_t steps)
	{
		for (size_t i = 0; i < steps; ++i)
		{
			++it;
		}
		std::cout << "[advance_cursor/std::forward_iterator] O(N) sequential advance selected.\n";
	}

	template <typename Iterator>
	requires std::random_access_iterator<Iterator>
	void advance_cursor(Iterator& it, size_t steps)
	{
		it += steps;
		std::cout << "[advance_cursor/std::random_access_iterator] O(1) random access advance selected`.\n";
	}
}