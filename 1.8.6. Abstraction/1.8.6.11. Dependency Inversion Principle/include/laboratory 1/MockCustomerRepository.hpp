#pragma once
#include "include/laboratory 1/ICustomerRepository.hpp"

namespace Infrastructure
{
	class MockCustomerRepository : public BusinessLogic::ICustomerRepository
	{
	public:
		~MockCustomerRepository() override = default;
		[[nodiscard]] int64_t get_credit_score(std::string_view customer_id) const override;

	};
}