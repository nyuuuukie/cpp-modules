#include "Utils.hpp"

std::string	Utils::toUpperCase(std::string src) {
	for (size_t i = 0; i < src.length(); i++)
	{
		if (std::islower(src[i]))
			src[i] = toupper(src[i]);
	}
	return src;
}

void	Utils::printLine(const std::string &text)
{
	std::cout << text << std::endl;
}

void	Utils::printColorLine(const std::string &text, const std::string color)
{
	std::cout << color;
	printLine(text);
	std::cout << DEF;
}