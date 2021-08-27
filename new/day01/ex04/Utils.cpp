#include "Utils.hpp"

std::string	Utils::toUpperCase(std::string src) {
	for (size_t i = 0; i < src.length(); i++)
	{
		if (std::islower(src[i]))
			src[i] = toupper(src[i]);
	}
	return src;
}

void	Utils::print(const std::string &text)
{
	std::cout << text << std::endl;
}

void	Utils::print(const std::string &text, const std::string color)
{
	std::cout << color;
	print(text);
	std::cout << DEFAULT;
}
