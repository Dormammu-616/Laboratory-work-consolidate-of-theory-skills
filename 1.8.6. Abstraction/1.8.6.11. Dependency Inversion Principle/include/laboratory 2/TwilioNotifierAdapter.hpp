#pragma once
#include "include/laboratory 2/INotifier.hpp"
#include "include/laboratory 2/TwilioApi.hpp"
#include <memory>
#include <string>

namespace Infrastructure
{
	class TwilioNotifierAdapter : public BusinessLogic::INotifier
	{
	public:
		TwilioNotifierAdapter(std::shared_ptr<ExternalVendor::TwilioApi> api, std::string phone_number);
		~TwilioNotifierAdapter() override = default;
		void send_notification(std::string_view message) const override;
	private:
		std::shared_ptr<ExternalVendor::TwilioApi> p_api;
		const std::string number;
	};
}