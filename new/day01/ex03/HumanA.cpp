#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	this->_name = name;
	std::cout << _name + " created." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

void
HumanA::attack(void)
{
	std::cout << _name << " attacks with his ";
	std::cout << _weapon.getType() << std::endl;
}