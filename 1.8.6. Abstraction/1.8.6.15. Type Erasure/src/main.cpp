#include "lab1/RenderPipeline.hpp"
#include "lab1/Shapes.hpp"
#include "lab2/SimulationGrid.hpp"
#include "lab2/SpaceObjects.hpp"
#include <iostream>

int main()
{
	std::cout << "*** Start laboratory #1 - Basic Concept/Model Idiom ***\n";
	{
		lab1::RenderPipeline pipeline{};
		lab1::Circle circle{};
		lab1::Square square{};
		lab1::ThirdParty::OptimizedMesh mesh{};

		pipeline.add_renderable(std::move(circle));
		pipeline.add_renderable(std::move(square));
		pipeline.add_renderable(std::move(mesh));

		pipeline.execute_frame();
	}
	std::cout << "*** End laboratory #1 ***\n\n";

	std::cout << "*** Start laboratory #2 - Type Erasure-Value Semantics ***\n";
	{
		lab2::SimulationGrid grid{};
		lab2::Asteroid asteroid{ 5000 };
		lab2::Starship starship("Falcon");
		lab2::ThirdParty::BlackHole blackhole{};

		grid.add_entity(asteroid);
		grid.add_entity(starship);
		grid.add_entity(blackhole);

		grid.duplicate_entity(0);
		grid.duplicate_entity(1);

		grid.run_tick();
	}
	std::cout << "*** End laboratory #2 ***\n\n";


	std::cout << "*** Start laboratory #3 -  ***\n";
	{
		
	}
	std::cout << "*** End laboratory #3 ***\n\n";

	return 0;
}