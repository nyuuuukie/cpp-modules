#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure") {
	this->_healPowerPercentage = rand() % 100;
}

Cure::~Cure(void) {}

Cure::Cure(const Cure &other) {
	*this = other;
}

Cure &Cure::operator=(const Cure &other) {
	if (this != &other) {
		_healPowerPercentage = other._healPowerPercentage;
	}
	return *this;
}

AMateria* Cure::clone() const {
	AMateria *clone = new Cure();

	*clone = *this;
	return clone;
}

int Cure::getPower() const {
	return _healPowerPercentage;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName()	<< "’s";
	std::cout << " wounds by " << getPower() << "% *" << std::endl;
}
