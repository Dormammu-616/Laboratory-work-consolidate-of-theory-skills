#pragma once
#include "lab1/IWindow.hpp"
#include <vector>

namespace lab1
{
	class ConsoleWindow : public IWindow
	{
	public:
		ConsoleWindow();
		~ConsoleWindow() override;
		void render() const override;
	private:
		std::vector<char> buffer{};
	};
}