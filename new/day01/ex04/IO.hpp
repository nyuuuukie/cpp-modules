#pragma once

#include <string>
#include <fstream>

class IO
{
private:

public:
	static std::string	readFromFile(std::string filename);
	static void			writeToFile(std::string filename, std::string text);
};



