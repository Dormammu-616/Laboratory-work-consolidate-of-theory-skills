#pragma once
#include "include/laboratory 2/INotifier.hpp"
#include <memory>

namespace BusinessLogic
{
	class UserManager
	{
	public:
		explicit UserManager(std::shared_ptr<BusinessLogic::INotifier> notifier);
		~UserManager() = default;
		void register_user(std::string_view username) const;
	private:
		std::shared_ptr<BusinessLogic::INotifier> p_notifier;
	};
}