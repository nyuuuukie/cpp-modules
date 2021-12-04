#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Anon_clap_name"), ScavTrap("Anon"),  FragTrap("Anon") 
{
	this->_type = "DI4M-TP";
	this->_hp = FragTrap::__hp__;
	this->_ep = ScavTrap::__ep__;
	this->_damage = FragTrap::__dmg__;
	
	std::cout << "Kureiji Daiyamondo! [Diamond constructor]" << std::endl;
}


DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_type = "DI4M-TP";
	this->_name = name;
	this->_hp = FragTrap::__hp__;
	this->_ep = ScavTrap::__ep__;
	this->_damage = FragTrap::__dmg__;

	std::cout << getInfo() << " Kureiji Daiyamondo! [Diamond constructor]" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
{
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->FragTrap::operator=(other);
		this->ScavTrap::operator=(other);
		this->_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << getInfo() << " destroyed! [Diamond destructor]" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI( void ) {
	std::cout << "WHOAMI:" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Clapname: " << ClapTrap::_name << std::endl;
}

