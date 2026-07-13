#include "lab2/SecurityPolicy.hpp"
#include <vector>
#include <memory>

namespace lab2
{
	class ConnectionPool
	{
	public:
		void add_policy(std::shared_ptr<lab2::SecurityPolicy> policy);
		void verify_all() const;
	private:
		std::vector<std::shared_ptr<lab2::SecurityPolicy>> policies{};
	};
}