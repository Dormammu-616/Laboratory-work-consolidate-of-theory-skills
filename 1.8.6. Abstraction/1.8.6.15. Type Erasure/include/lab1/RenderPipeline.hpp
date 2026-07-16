#pragma once
#include "lab1/AnyRenderable.hpp"
#include <vector>

namespace lab1
{
	class RenderPipeline
	{
	public:
		void add_renderable(lab1::AnyRenderable&& obj);
		void execute_frame() const;
	private:
		std::vector<lab1::AnyRenderable> vec_{};
	};
}