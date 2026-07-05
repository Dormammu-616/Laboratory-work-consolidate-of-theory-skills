#pragma once
#include <iostream>
#include <string_view>

namespace lab3
{
	template <typename Base> class MetricsMixin : public Base
	{
	public:
		template <typename ... Args> MetricsMixin(Args&&... args) : Base(std::forward<Args>(args)...) {}

		void handle_request(std::string_view req)
		{
			++requests_processed;

			std::cout << "[MetricsMixin] Total processed by this pipeline '"<< requests_processed << "'.\n";

			Base::handle_request(req);
		}

		static constexpr bool is_cacheable{ Base::is_cacheable };
	private:
		inline static size_t requests_processed{ 0 };
	};
}