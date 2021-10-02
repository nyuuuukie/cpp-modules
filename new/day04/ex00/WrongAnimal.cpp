#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {
	std::cout << "[WrongAnimal constructor]" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "[WrongAnimal destructor]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

const std::string& WrongAnimal::getType( void ) const {
	return _type;
}

void WrongAnimal::setType( const std::string &type) {
	this->_type = type;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "*WrongAnimal sounds*" << std::endl;
}
