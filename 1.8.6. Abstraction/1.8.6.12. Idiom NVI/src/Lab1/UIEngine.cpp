#include "Lab1/UIEngine.hpp"
#include <iostream>

void UIEngine::render_UI(const std::vector<std::shared_ptr<Widget>>& widgets)
{
	std::cout << "[UIEngine] Start widget...\n\n";

	for (const auto& elem : widgets)
	{
		elem->render();
	}

	std::cout << "[UIEngine] End widget...\n";
}