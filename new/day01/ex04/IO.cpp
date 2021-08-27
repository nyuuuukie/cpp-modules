#include "IO.hpp"

std::string	IO::readFromFile(std::string filename)
{
	std::string input;
	std::string total;
	
	total = "";
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
		_code = READ_SUCCESS;
		file.close();
	}
	else
	{
		_code = READ_FILE_ERROR;
		printColorLine("File " + _input + " not found.", RED);
	}
	return total;
}

void	IO::writeToFile(std::string filename, std::string text)
{
	std::ofstream file;

	file.open(filename, std::ofstream::trunc);
		
	if (file.is_open())
	{
		file << text;
		if (_code != STRING_NOT_FOUND)
			_code = WRITE_SUCCESS;
	}
	else
	{
		printLine("File " + _output + " cannot not be opened.");
	}
	file.close();
}