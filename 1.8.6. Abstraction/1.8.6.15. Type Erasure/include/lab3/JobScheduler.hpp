#pragma once
#include "lab3/AnyJob.hpp"
#include <vector>

namespace lab3
{
	class JobScheduler
	{
	public:
		void schedule(AnyJob job);
		void run_all();
	private:
		std::vector<lab3::AnyJob> queue_{};
	};
}