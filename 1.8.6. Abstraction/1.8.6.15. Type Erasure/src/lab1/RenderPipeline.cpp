#include "lab1/RenderPipeline.hpp"
#include <iostream>

void lab1::RenderPipeline::add_renderable(lab1::AnyRenderable&& obj)
{
	vec_.push_back(std::move(obj));
	std::cout << "[RenderPipeline] New rendering object added.\n";
}

void lab1::RenderPipeline::execute_frame() const
{
	std::cout << "[RenderPipeline] Executing frame...\n";

	for (const auto& obj : vec_)
	{
		obj.render();
		std::cout << "-------\n";
	}
}