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

void Karen::undef( void ) {
	std::cout << "Probably complaining about insignificant problems" << std::endl;
}

void Karen::complain( std::string level ) {
	int lvl = -1;
	for (int i = 0; i < 4; i++) {
		if (this->levels[i] == level)
			lvl = i;
	}
	
	switch (lvl) {
		case 0:
			(this->*(func[0]))();
		case 1:
			(this->*(func[1]))();
		case 2:
			(this->*(func[2]))();
		case 3:
			(this->*(func[3]))();
			break;
		default:
			this->undef();
			break;
	}
}
