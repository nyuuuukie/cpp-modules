#include "Dog.hpp"

Dog::Dog( void ) {
	setType("Dog");
	std::cout << "[Dog constructor]" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "[Dog destructor]" << std::endl;
}

Dog::Dog(const Dog &other) {
	*this = other;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		this->Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound( void ) const {
	std::cout << "*woof woof*" << std::endl;
}
