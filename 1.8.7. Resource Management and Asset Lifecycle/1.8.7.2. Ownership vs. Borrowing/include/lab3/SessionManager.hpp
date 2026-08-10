#pragma once
#include "lab3/ClientSession.hpp"
#include <vector>
#include <memory>

namespace lab3
{
	class SessionManager
	{
	public:
		std::shared_ptr<lab3::ClientSession> create_session(int64_t id);
		void drop_session(int64_t id);
	private:
		std::vector<std::shared_ptr<lab3::ClientSession>> active_session_;
	};
}