#pragma once
#include <iostream>
#include <string_view>

namespace lab3
{
	template <typename Base> class AdaptiveCacheMixin : public Base
	{
	public:
		template <typename ... Args> AdaptiveCacheMixin(Args&&... args) : Base(std::forward<Args>(args)...) {}

		void handle_request(std::string_view req)
		{
			if constexpr (Base::is_cacheable)
			{
				std::cout << "[AdaptiveCacheMixin] Saving in cache...\n";
			}
			else
			{
				std::cout << "[AdaptiveCacheMixin] Skip (caching not supported)...\n";
			}

			Base::handle_request(req);
		}

		static constexpr bool is_cacheable{ Base::is_cacheable };
	};
}