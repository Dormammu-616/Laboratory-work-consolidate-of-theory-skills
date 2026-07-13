#pragma once
#include <iostream>

namespace lab2
{
	class SecurityPolicy
	{
	public:
		void check_clearance() const
		{
			std::cout << "\t[SecurityPolicy] Clearance check passed.\n";
		}
	protected:
		~SecurityPolicy() // должно использоваться  `= default`, но для наглядности нашей учебной цели реализуем тело деструктора с std::cout.
		{
			std::cout << "[SecurityPolicy] Base destroyed.\n";
		}
		SecurityPolicy() = default;
		SecurityPolicy(const SecurityPolicy&) = default;
		SecurityPolicy& operator=(const SecurityPolicy&) = default;
		SecurityPolicy(SecurityPolicy&&) = default;
		SecurityPolicy& operator=(SecurityPolicy&&) = default;
	};
}