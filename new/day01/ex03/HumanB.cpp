#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = nullptr;
	std::cout << name + " created." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

void
HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void
HumanB::attack(void) {
	std::cout << _name << " attacks with his ";
	std::cout << _weapon->getType() << std::endl;
}