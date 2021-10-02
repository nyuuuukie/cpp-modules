#include "Cat.hpp"

Cat::Cat( void ) {
	setType("Cat");
	std::cout << "[Cat constructor]" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "[Cat destructor]" << std::endl;
}

Cat::Cat(const Cat &other) {
	*this = other;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		this->Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "*nya nya*" << std::endl;
}
