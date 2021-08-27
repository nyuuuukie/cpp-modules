#include "Replacer.hpp"
#include "IO.hpp"
#include "Utils.hpp"

Replacer::Replacer(void)
{
	_code = DEFAULT;
	Utils::printLine("");
	Utils::printColorLine("I solemnly swear that I am up to no good.", WHITE);
	Utils::printLine("");
}	

Replacer::Replacer(std::string filename, std::string replacee, std::string replacer)
{
	this->_code = DEFAULT;
	this->_input = filename;
	this->_replacee = replacee;
	this->_replacer = replacer;
	this->setExtension("replace");
	this->setOutput(filename);
	printColorLine("I solemnly swear that I am up to no good.", WHITE);
}

Replacer::~Replacer(void)
{
	printLine("");
	if (_code == WRITE_SUCCESS)
		printColorLine("Mischief managed.", WHITE);
	printColorLine("Nox.", WHITE);
}

code	Replacer::getCode(void)
{
	return this->_code;
}

void	Replacer::setExtension(std::string ext)
{
	this->_extension = ext;
	this->setOutput(_input);
}

void	Replacer::setReplacee(std::string text)
{
	if (text.compare("") == 0) {
		_code = BAD_ARGUMENTS;
	}
	else {
		this->_replacee = text;
	}
}

void	Replacer::setReplacer(std::string text)
{
	if (text.compare("") == 0) {
		_code = BAD_ARGUMENTS;
	}
	else {
		this->_replacer = text;
	}
}

void	Replacer::setInput(std::string filename)
{
	if (filename.compare("") == 0) {
		_code = BAD_ARGUMENTS;
	}
	else {
		this->_input = filename;
		this->setOutput(filename);
	}
}

void	Replacer::setOutput(std::string filename)
{
	if (filename.compare("") == 0) {
		_code = BAD_ARGUMENTS;
	}
	else {
		_code = DEFAULT;
		this->_output = Utils::toUpperCase(filename) + "." + _extension;
	}
}

void	Replacer::makeReplace(void)
{
	std::string total;
	size_t start;

	start = 0;
	total = readFromFile();
	if (_code == READ_SUCCESS)
	{
		_code = STRING_NOT_FOUND;
		while ((start = total.find(_replacee, start)) != std::string::npos)
		{
			total.replace(start, _replacee.length(), _replacer);
			_code = REPLACE_SUCCESS;
		}
		writeToFile(total);
	}
}
