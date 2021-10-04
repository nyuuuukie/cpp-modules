#include "Dog.hpp"

Dog::Dog( void ) {
	setType("Dog");
	_brain = new Brain();
	std::cout << "[Dog constructor]" << std::endl;
}

Dog::~Dog( void ) {
	if (_brain != 0)
		delete _brain;
	std::cout << "[Dog destructor]" << std::endl;
}

Dog::Dog(const Dog &other) : _brain(0) {
	if (this->_brain == 0)
		this->_brain = new Brain();
	
	std::cout << "Cloning dog..." << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "*woof woof*" << std::endl;
}

Brain *Dog::getBrain( void ) const {
	return this->_brain;
}
