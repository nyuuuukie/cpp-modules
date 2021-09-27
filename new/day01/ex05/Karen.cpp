#include "Karen.hpp"
#include <iostream>

Karen::Karen() {
	func[0] = &Karen::debug;
	func[1] = &Karen::info;
	func[2] = &Karen::warning;
	func[3] = &Karen::error;

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

Karen::~Karen() {}

void Karen::debug( void ) {
	std::cout << "DEBUG: " << "No more printf." << std::endl;
}

void Karen::info( void ) {
	std::cout << "INFO: " << "You dont have to use norme anymore." << std::endl;
}

void Karen::warning( void ) {
	std::cout << "WARN: " << "You should switch language to C++." << std::endl;
}

void Karen::error( void ) {
	std::cout << "ERR: " << "How dare you not to put endline?!" << std::endl;
}
	
bool Karen::run( int index ) {
	(this->*(func[index]))();
	return false;
}

void Karen::complain( std::string level ) {
	for (int i = 0; i < 4; i++) {
		(levels[i] == level) && run(i);
	}
}
