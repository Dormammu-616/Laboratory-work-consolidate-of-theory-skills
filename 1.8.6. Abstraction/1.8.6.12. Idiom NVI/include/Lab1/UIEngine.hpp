#pragma once
#include "Lab1/Widget.hpp"
#include <vector>
#include <memory>

namespace UIEngine
{
	void render_UI(const std::vector<std::shared_ptr<Widget>>& widgets);
}