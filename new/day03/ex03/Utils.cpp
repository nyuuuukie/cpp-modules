#include "Utils.hpp"

std::string
Utils::itos(int number, int base)
{
	std::string res = "";

	if (number / base)
		res = itos(number / base, base);
	if (number % base < 10)
		res += number % base + '0';
	else
		res += number % base - 10 + 'A';
	return res;
}
