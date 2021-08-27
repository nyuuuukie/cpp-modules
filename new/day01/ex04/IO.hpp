#pragma once

#include <string>
#include <fstream>

class IO
{
	public:
		static int	read(std::string filename, std::string &total);
		static int	write(std::string filename, std::string text);
};



