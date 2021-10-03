#include "Animal.hpp"

Animal::Animal( void ) {
	std::cout << "[Animal constructor]" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "[Animal destructor]" << std::endl;
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other) {
		std::cout << "Cloning animal..." << std::endl;
		this->_type = other._type;
	}
	return *this;
}

const std::string& Animal::getType( void ) const {
	return _type;
}

void Animal::setType( const std::string &type) {
	this->_type = type;
}

void Animal::makeSound( void ) const {
	std::cout << "*Animal sounds*" << std::endl;
}
