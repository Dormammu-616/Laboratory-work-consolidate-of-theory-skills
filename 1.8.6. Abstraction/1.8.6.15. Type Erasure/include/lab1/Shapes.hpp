#pragma once
#include <iostream>

namespace lab1
{
	class Circle
	{
	public:
		void render() const
		{
			std::cout << "[Circle] Rendering Circle.\n";
		}
	};

	class Square
	{
	public:
		void render() const
		{
			std::cout << "[Square] Rendering Square.\n";
		}
	};

	namespace ThirdParty
	{
		class OptimizedMesh
		{
		public:
			void render() const
			{
				std::cout << "[ThirdParty::OptimizedMesh] Rendering highly optimized Third-Party Mesh.\n";
			}
		};
	}
}