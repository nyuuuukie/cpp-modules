#pragma once

#include <iostream>

#define RED "\033[31m"
#define DEF "\033[0m"
#define WHITE "\033[37m"

enum code
{
	DEFAULT = -3,
	BAD_ARGUMENTS = -2,
	READ_FILE_ERROR = -1,
	REPLACE_SUCCESS = 0,
	READ_SUCCESS = 1,
	WRITE_SUCCESS = 2,
	STRING_NOT_FOUND = 3
};

class Replacer
{
	public:
		Replacer(void);
		~Replacer(void);
		Replacer(std::string filename, std::string replacee, std::string replacer);
		
		void	makeReplace(void);
	
		//Getters and setters
		code	getCode(void);
		void	setReplacee(std::string text);
		void	setReplacer(std::string text);	
		void 	setExtension(std::string ext);
		void	setInput(std::string filename);
		void	setOutput(std::string filename);
	
	private:
		code	_code;
		std::string	_replacer;
		std::string	_replacee;
		std::string	_extension;
		std::string	_input;
		std::string	_output;
};
