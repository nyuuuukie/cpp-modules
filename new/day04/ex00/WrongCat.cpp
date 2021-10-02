#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {
	setType("WrongCat");
	std::cout << "[WrongCat constructor]" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "[WrongCat destructor]" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) {
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		this->WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound( void ) const {
	std::cout << "*nya nya*" << std::endl;
}
