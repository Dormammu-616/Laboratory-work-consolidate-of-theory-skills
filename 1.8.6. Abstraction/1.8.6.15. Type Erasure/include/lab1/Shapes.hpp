#pragma once
#include <iostream>

namespace lab1
{
	class Circle
	{
	public:
		void render() const
		{
			std::cout << "\t[Circle] Rendering Circle.\n";
		}
	};

	class Square
	{
	public:
		void render() const
		{
			std::cout << "\t[Square] Rendering Square.\n";
		}
	};

	namespace ThirdParty
	{
		class OptimizedMesh
		{
		public:
			void render() const
			{
				std::cout << "\t[ThirdParty::OptimizedMesh] Rendering highly optimized Third-Party Mesh.\n";
			}
		};
	}
}