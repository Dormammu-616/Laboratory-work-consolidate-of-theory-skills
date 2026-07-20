#include "lab3/JobScheduler.hpp"
#include <iostream>

void lab3::JobScheduler::schedule(AnyJob job)
{
	std::cout << "[JobScheduler] Adding job...\n";
	queue_.push_back(std::move(job));
}

void lab3::JobScheduler::run_all()
{
	std::cout << "[JobScheduler] Iterating through the queue...\n";

	for (auto& obj : queue_)
	{
		if (obj.execute())
		{
			std::cout << "[JobScheduler] A job completed successfully!.\n";
		}
		else
		{
			std::cout << "[JobScheduler] Warning: A job has failed!\n";
		}
	}
}