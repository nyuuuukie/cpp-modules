#include "Cat.hpp"

Cat::Cat( void ) {
	setType("Cat");
	_brain = new Brain();
	std::cout << "[Cat constructor]" << std::endl;
}

Cat::~Cat( void ) {
	if (_brain != 0)
		delete _brain;
	std::cout << "[Cat destructor]" << std::endl;
}

Cat::Cat(const Cat &other) {
	*this = other;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other) {
		std::cout << "Cloning cat..." << std::endl;
		this->Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

void Cat::makeSound( void ) const {
	std::cout << "*nya nya*" << std::endl;
}

Brain *Cat::getBrain( void ) const {
	return this->_brain;
}

void Cat::setBrain( Brain *brain) {
	this->_brain = brain;
}
