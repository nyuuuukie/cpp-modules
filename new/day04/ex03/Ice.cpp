#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice") {
	_powerPercentage = rand() % 100;
}

Ice::~Ice(void) {}

Ice::Ice(const Ice &other) {
	*this = other;
}

Ice &Ice::operator=(const Ice &other) {
	if (this != &other) {
		this->_powerPercentage = other._powerPercentage;
	}
	return *this;
}

AMateria* Ice::clone() const {
	AMateria *clone = new Ice();

	*clone = *this;
	return clone;
}

int Ice::getPower(void) const {
	return _powerPercentage;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " taking " << getPower() << "hp *" << std::endl;
}
