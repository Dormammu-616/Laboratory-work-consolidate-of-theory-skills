#pragma once
#include "lab3/ClientSession.hpp"
#include <vector>
#include <memory>

namespace lab3
{
	class SessionObserver
	{
	public:
		void subscribe(std::shared_ptr<lab3::ClientSession> session);
		void report_active_sessions();
	private:
		std::vector<std::weak_ptr<ClientSession>> watched_session_;
	};
}