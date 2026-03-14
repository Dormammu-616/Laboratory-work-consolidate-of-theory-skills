#include "Architectural pattern Taxonomy.h"
#include "ICloudResource.h"
#include "DockerContainer.h"
#include "PodmanContainer.h"
#include <iostream>
#include <vector>

void Taxonomy::run_lab()
{
	std::cout << "*** Start lab #1 ***\n"
		<< "--- Creating specific instances ---\n";

	std::vector<ICloudResource*> specific_inst{};
	specific_inst.emplace_back(new DockerContainer{});
	specific_inst.emplace_back(new PodmanContainer{});

	for (auto& obj : specific_inst)
	{
		obj->deploy();
		obj->destroy();
		obj->getHourlyRate();
		obj->start();
		obj->stop();

		std::cout << "\n";
	}

	std::cout << "--- Delete specific instances ---\n";
	for (auto obj : specific_inst)
	{
		std::cout << "\tdelete obj!\n";
		delete obj;
	}
	specific_inst.clear();
	
	// ќЎ»Ѕ »  ќћѕ»Ћя÷»» - невозможно создать экземпл€ры абстрактных классов:
	//specific_inst.emplace_back(new ICloudResource{});				// 1 уровень абстракции - 5 долгов
	//specific_inst.emplace_back(new AbstractComputeInstance{});	// 2 уровень абстрациии - 3 долга
	//specific_inst.emplace_back(new AbstractContainer{});			// 3 уровень абстрациии - 2 долга
		
	std::cout << "*** End lab #1 ***\n\n";
}