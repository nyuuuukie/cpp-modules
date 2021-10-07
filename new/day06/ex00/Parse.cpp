#include "Parse.hpp"
#include <cstdlib>
#include <limits>

const std::string Parse::_whitespaces = " \n\r\t\f\v";

Parse::Parse(std::string arg) {
	_parsers[0] = &Parse::toChar;
	_parsers[1] = &Parse::toInt;
	_parsers[2] = &Parse::toFloat;
	_parsers[3] = &Parse::toDouble;

	_prefixes[0] = "Char: ";
	_prefixes[1] = "Int: ";
	_prefixes[2] = "Float: ";
	_prefixes[3] = "Double: ";

	_arg = trim(arg);
	setFloatTail();
}

Parse::~Parse() {}

Parse::Parse(const Parse &other) {
	*this = other;
}

Parse &Parse::operator=(const Parse &other) {
	if (this != &other) {
		this->_arg = other._arg;
		this->_floatTail = other._floatTail;
	}
	return *this;
}

std::string Parse::trim(const std::string &s) {

    size_t start = s.find_first_not_of(_whitespaces);
    size_t end = s.find_last_not_of(_whitespaces);
	
	if (start == std::string::npos) 
		start = 0;
    if (end == std::string::npos)
		end = s.length();
		
	return s.substr(start, end + 1);
}

void Parse::setFloatTail( void ) {
	char *end = 0;
	std::strtol(_arg.c_str(), &end, 10);

	_floatTail = std::string(end).length() - 1;

	if (end[_floatTail] == 'f')
		_floatTail--;
	
	if (_floatTail < 1)
		_floatTail = 1;
}

int Parse::parse() {
	int res = 0;

	for (int i = 0; i < Parse::_parsersCount; i++)
	{
		try {
			std::cout << _prefixes[i];
			(this->*_parsers[i])();
		}
		catch (ParseError &e) {
			std::cout << e.what() << std::endl;
			res = 2;
		}
	}
	return res;
}

int Parse::readInt( void ) {
	char *end = 0;
	long num = std::strtol(_arg.c_str(), &end, 10);

	readDouble();
	if (*end != '\0' && *end != '.')
		throw InvalidParse();

	return num;
}

double Parse::readDouble( void ) {
	char *end = 0;
	double num = std::strtod(_arg.c_str(), &end);
	
	std::string e(end);
	if (e != "" && e != "f")
		throw InvalidParse();

	return num;
}

void Parse::toInt( void ) {

	int num = static_cast<int>(readInt());

	std::cout << num << std::endl;
}

void Parse::toChar( void ) {

	int num = static_cast<int>(readInt());
		
	if (num <= 32 || num == 127) {
		throw NonDisplayable();
	}

	if ((num < std::numeric_limits<char>::min()) 
	 || (num > std::numeric_limits<char>::max()))
		throw InvalidParse();
	
	std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
}

void Parse::toFloat( void ) {

	float num = static_cast<float>(readDouble());

	std::cout.precision(_floatTail);
 	std::cout << std::fixed;
	std::cout << num << "f" << std::endl;
}

void Parse::toDouble( void ) {

	double num = static_cast<double>(readDouble());

	std::cout.precision(_floatTail);
 	std::cout << std::fixed;
	std::cout << num << std::endl;
}

const char *Parse::InvalidParse::what() const throw() {
	return "Impossible";
}

const char *Parse::NonDisplayable::what() const throw() {
	return "Non displayable";
}
