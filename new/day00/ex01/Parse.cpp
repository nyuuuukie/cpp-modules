#include "Parse.hpp"

int Parse::stoi(std::string s, int &res)
{
	int i = 0;
	int num = 0;

	while (s[i] != '\0' && s[i] <= ' ')
		i++;
	if (s[i] == '\0')
		return (1);

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (2);
		if (num * 10 + (s[i] - '0') < 0)
			return (3);
		num = num * 10 + (s[i] - '0');
		i++;
	}
	res = num;
	return (0);
}

std::string
Parse::itos(int number, int base)
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
