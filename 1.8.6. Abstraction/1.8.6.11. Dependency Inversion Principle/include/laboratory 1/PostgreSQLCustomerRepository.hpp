#pragma once
#include "include/laboratory 1/ICustomerRepository.hpp"

namespace Infrastructure
{
	class PostgreSQLCustomerRepository : public BusinessLogic::ICustomerRepository
	{
	public:
		~PostgreSQLCustomerRepository() override = default;
		[[nodiscard]] int64_t get_credit_score(std::string_view customer_id) const override;
	};
}