#pragma once

#include <iostream>

class Replacer
{
	public:
		Replacer(void);
		~Replacer(void);
		Replacer(std::string filename, std::string replacee, std::string replacer);
		
		int		makeReplace(void);
		int		setReplacee(std::string text);
		int		setReplacer(std::string text);
		int		setExtension(std::string ext);
		int		setInput(std::string filename);
		int		setOutput(std::string filename);
	
	private:
		std::string	_replacer;
		std::string	_replacee;
		std::string	_extension;
		std::string	_input;
		std::string	_output;
};
