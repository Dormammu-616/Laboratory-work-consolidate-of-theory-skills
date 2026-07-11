#pragma once

namespace lab1
{
	class IWindow
	{
	public:
		IWindow() = default;
		virtual ~IWindow() = default;
		IWindow(const IWindow& window) = delete;
		IWindow& operator=(const IWindow& window) = delete;
		IWindow(IWindow&& window) = delete;
		IWindow& operator=(IWindow&& window) = delete;
		virtual void render() const = 0;
	};
}