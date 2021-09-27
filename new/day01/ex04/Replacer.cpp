#include "Replacer.hpp"
#include "IO.hpp"
#include "Utils.hpp"

Replacer::Replacer(void)
{
	Utils::print("I solemnly swear that I am up to no good.", MAGENTA);
	Utils::print("");
}

Replacer::Replacer(std::string filename, std::string replacee, std::string replacer)
{
	this->_input = filename;
	this->_replacee = replacee;
	this->_replacer = replacer;
	this->setExtension("replace");
	this->setOutput(filename);
	Utils::print("I solemnly swear that I am up to no good.", MAGENTA);
}

Replacer::~Replacer(void)
{
	Utils::print("");
	Utils::print("Mischief managed.", MAGENTA);
}

int
Replacer::setExtension(std::string ext)
{
	this->_extension = ext;
	this->setOutput(_input);
	return 0;
}

int
Replacer::setReplacee(std::string text)
{
	if (text.compare("") == 0) {
		return 1;
	}
	this->_replacee = text;
	return 0;
}

int
Replacer::setReplacer(std::string text)
{
	this->_replacer = text;
	return 0;
}

int
Replacer::setInput(std::string filename)
{
	if (filename.compare("") == 0) {
		return 1;
	}
	this->_input = filename;
	this->setOutput(filename);
	return 0;
}

int
Replacer::setOutput(std::string filename)
{
	if (filename.compare("") == 0) {
		return 1;
	}
	this->_output = Utils::toUpperCase(filename) + "." + _extension;
	return 0;
}

int
Replacer::makeReplace(void)
{
	std::string total;
	std::string leftPart; 
	std::string rightPart;

	if (IO::read(_input, total)) {
		Utils::print("File " + _input + " not found or cannot be opened.", RED);
		return 1;
	}

	size_t start = 0;
	bool found = false;
	while ((start = total.find(_replacee, start)) != std::string::npos) {
		leftPart = total.substr(0, start);
		rightPart = total.substr(start + _replacee.length(), total.length() - 1);
		total = leftPart + _replacer + rightPart;
		//total = total.substr(0, start) + _replacer + total.substr(start + _replacee.length(), total.length() - 1);
		found = true;
	}

	if (IO::write(_output, total)) {
		Utils::print("File " + _output + " cannot be opened.");
		return 1;
	}

	if (!found) {
		Utils::print("Pattern " + _replacee + " not found.", RED);
	}
	return 0;
}
