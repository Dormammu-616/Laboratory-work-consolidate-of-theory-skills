#include "lab3/SessionObserver.hpp"
#include <iostream>

void lab3::SessionObserver::subscribe(std::shared_ptr<lab3::ClientSession> session)
{
	std::cout << "[SessionObserver] Subscription process.\n";

	watched_session_.push_back(session);
}

void lab3::SessionObserver::report_active_sessions()
{
	std::cout << "[SessionObserver] Active sessions.\n";

	std::erase_if(watched_session_, [](const std::weak_ptr<lab3::ClientSession>& wp)
		{
			if (wp.expired())		// проверяет, жив ли объект, без создания shared_ptr
			{
				std::cout << "\t[SessionObserver] Session expired and removed.\n";
				return true;		// Удалить элемент
			}

			return false;			// Оставить элемент
		});

	for (const auto& session : watched_session_)
	{
		if (auto shared_ptr = session.lock())
		{
			std::cout << "\t[SessionObserver] The object '" << shared_ptr->get_id() << "' is alive!.\n";
			shared_ptr->ping();
		}
	}
}