#include "IO.hpp"

int
IO::read(std::string filename, std::string &total)
{
	std::string input;

	std::ifstream file(filename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, input);
			total += input;
			if (!file.eof())
				total += "\n";
		}
		file.close();
		return 0;
	}
	return 1;
}

int
IO::write(std::string filename, std::string text)
{
	std::ofstream file;

	file.open(filename, std::ofstream::trunc);
		
	if (file.is_open())
	{
		file << text;
		file.close();
		return 0;
	}
	return 1;
}
