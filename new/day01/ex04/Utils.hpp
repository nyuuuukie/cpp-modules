#pragma once

# include <string>
# include <iostream>
 
# define DEFAULT "\033[0m"
# define WHITE "\033[37m"
# define RED "\033[31m"
# define MAGENTA "\033[35m"


class Utils
{
	public:
		static std::string toUpperCase(std::string src);
		static void	print(const std::string &text);
		static void	print(const std::string &text, const std::string color);
};
