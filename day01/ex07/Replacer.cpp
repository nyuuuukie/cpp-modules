/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:46:30 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/14 19:00:33 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

typedef std::string string;

void	printLine(const std::string &text)
{
	std::cout << text << std::endl;
}

Replacer::Replacer(void)
{
	_code = DEFAULT;
	std::cout << "I solemnly swear that I am up to no good." << std::endl;
}	

Replacer::Replacer(string filename, string toReplace, string replacer)
{
	this->_code = DEFAULT;
	this->_inputFilename = filename;
	this->_toReplace = toReplace;
	this->_replacer = replacer;
	this->setExtension("replace");
	this->setOutputFilename(filename);
}

Replacer::~Replacer(void)
{
	if (_code == WRITE_SUCCESS)
		printLine("Mischief managed.");
	printLine("Nox.");
}

code Replacer::getCode(void)
{
	return this->_code;
}

void Replacer::setExtension(string ext)
{
	this->_extension = ext;
	this->setOutputFilename(_inputFilename);
}

void	Replacer::whatReplace(string text)
{
	if (text.compare("") == 0)
	{
		_code = BAD_ARGUMENTS;
	}
	else
	{
		this->_toReplace = text;
	}
}

void	Replacer::whatReplaceWith(string text)
{
	if (text.compare("") == 0)
	{
		_code = BAD_ARGUMENTS;
	}
	else
	{
		this->_replacer = text;
	}
}

void	Replacer::setInputFilename(string filename)
{
	if (filename.compare("") == 0)
	{
		_code = BAD_ARGUMENTS;
	}
	else
	{
		this->_inputFilename = filename;
		this-> setOutputFilename(filename);
	}
}

void	Replacer::setOutputFilename(string filename)
{
	if (filename.compare("") == 0)
	{
		_code = BAD_ARGUMENTS;
	}
	else
	{
		this->_outputFilename = toUpperCase(filename) + "." + _extension;
	}
}

string	Replacer::toUpperCase(string src)
{
	for (size_t i = 0; i < src.length(); i++)
	{
		if (std::islower(src[i]))
			src[i] = toupper(src[i]);
	}
	return src;
}

string Replacer::readFromFile(void)
{
	string input;
	string total;
	
	total = "";
	std::ifstream file(_inputFilename);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, input);
			total += "\n" + input;
		}
		_code = READ_SUCCESS;
	}
	else
	{
		_code = READ_FILE_ERROR;
		printLine("File " + _inputFilename + " not found.");
	}
	file.close();
	return total;
}

void	Replacer::writeToFile(string text)
{
	std::ofstream file;

	file.open(_outputFilename);
		
	if (file.is_open())
	{
		file << text;
		_code = WRITE_SUCCESS;
	}
	else
	{
		printLine("File " + _outputFilename + " could not be opened.");
	}
	file.close();
}

void	Replacer::makeReplace(void)
{
	string total;
	size_t start;
	size_t end;

	start = 0;
	total = readFromFile();
	if (_code == READ_SUCCESS)
	{
		_code = STRING_NOT_FOUND;
		while ((start = total.find(_toReplace, start)) != string::npos)
		{
			end = start + _toReplace.length() - 1;
			total.replace(start, end, _replacer);
			_code = REPLACE_SUCCESS;
		}
		writeToFile(total);
	}
}
