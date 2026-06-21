#pragma once
#include <cstdint>
#include <string_view>

namespace BusinessLogic
{
	class ICustomerRepository
	{
	public:
		virtual ~ICustomerRepository() = default;
		[[nodiscard]] virtual int64_t get_credit_score(std::string_view customer_id) const = 0;
	};
}
