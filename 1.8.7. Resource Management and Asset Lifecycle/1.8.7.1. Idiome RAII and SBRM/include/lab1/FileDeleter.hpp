#pragma once
#include <cstdio>
#include <iostream>

namespace lab1
{
	struct FileDeleter
	{
		void operator() (FILE* file) const noexcept
		{
			if (file)
			{
				std::cout << "[FileDeleter] File is valid. Closing file...\n";
				std::fclose(file);
				return;
			}

			std::cout << "[FileDeleter] File does not exist.\n";
		}
	};
}