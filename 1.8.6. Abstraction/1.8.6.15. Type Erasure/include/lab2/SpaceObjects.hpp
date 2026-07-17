#pragma once
#include <cstdint>
#include <string>

namespace lab2
{
	class Asteroid
	{
	public:
		Asteroid(const int64_t val) : mass_(val) {};
		void simulate() const
		{
			std::cout << "\t[Asteroid] Mass '"<< mass_ <<"', adress '"<< this << "'\n";
		}
	private:
		int64_t mass_{};
	};

	class Starship
	{
	public:
		Starship(const std::string& val) : name(val) {};
		void simulate() const
		{
			std::cout << "\t[Starship] Name '" << name << "', ardess '" << this << "'.\n";
		};
	private:
		std::string name{ "NoName" };
	};

	namespace ThirdParty
	{
		class BlackHole
		{
		public:
			void simulate() const
			{
				std::cout << "\t[ThirdParty::BlackHole] Consuming light, adress '" << this << "'.\n";
			}
		private:

		};
	}
}