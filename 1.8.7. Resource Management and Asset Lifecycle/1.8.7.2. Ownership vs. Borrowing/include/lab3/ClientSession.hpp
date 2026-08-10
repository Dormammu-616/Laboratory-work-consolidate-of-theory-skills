#pragma once
#include <cstdint>

namespace lab3
{
	class ClientSession
	{
	public:
		ClientSession(int64_t id);
		~ClientSession();
		ClientSession(const ClientSession&) = delete;
		ClientSession& operator=(const ClientSession&) = delete;
		ClientSession& operator=(ClientSession&&) = delete;
		ClientSession(ClientSession&&) = delete;
		[[nodiscard]] int64_t get_id() const;
		void ping() const;
	private:
		int64_t session_id_{ 0 };
	};
}