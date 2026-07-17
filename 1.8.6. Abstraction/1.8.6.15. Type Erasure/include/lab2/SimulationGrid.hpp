#pragma once
#include "lab2/AnySimulatable.hpp"
#include <vector>

namespace lab2
{
	class SimulationGrid
	{
	public:
		void add_entity(lab2::AnySimulatable entity);
		void duplicate_entity(size_t index);
		void run_tick() const;
	private:
		std::vector<lab2::AnySimulatable> grid_{};
	};
}