#include "lab2/SimulationGrid.hpp"
#include <iostream>

void lab2::SimulationGrid::add_entity(lab2::AnySimulatable entity)
{
	grid_.push_back(std::move(entity));
	std::cout << "[SimulationGrid] New entity successfully added!\n";
}

void lab2::SimulationGrid::duplicate_entity(size_t index)
{
	grid_.push_back(grid_[index]);
	std::cout << "[SimulationGrid] Duplicate entity successfully created! Used index '"<< index <<"'\n";
}

void lab2::SimulationGrid::run_tick() const
{
	std::cout << "[SimulationGrid] Run simulate...\n";

	for (const auto& obj : grid_)
	{
		obj.simulate();
		std::cout << "-------";
	}
}