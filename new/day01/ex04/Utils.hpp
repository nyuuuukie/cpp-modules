#pragma once

#include <string>
#include <iostream>

class Utils
{
private:

public:
	static std::string toUpperCase(std::string src);
	static void	printLine(const std::string &text);
	static void	printColorLine(const std::string &text, const std::string color);
};


