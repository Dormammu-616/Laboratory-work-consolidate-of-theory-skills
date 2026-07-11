#pragma once
#include "lab1/IWindow.hpp"
#include <vector>
#include <memory>

namespace lab1
{
	class SessionManager
	{
	public:
		void add_window(std::unique_ptr<lab1::IWindow> window);
		void render_all() const;
	private:
		std::vector<std::unique_ptr<lab1::IWindow>> active_windows;
	};
}