#pragma once
#include <string>
#include <cstdint>
#include <iostream>

namespace lab1
{
	struct UserRecord
	{
		std::string name{"NoName"};
		int64_t age{0};
		std::string serialize() const
		{
			std::cout << "\t[UserRecord] Contains: name '"<< name << "', age '"<< age << "'.\n";
			return name;
		}
	};
}