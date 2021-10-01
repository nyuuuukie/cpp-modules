#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap("Anon"), ScavTrap("Anon")
{
	this->_name = "Anon";
	this->_type = "DI4M-TP";
	ClapTrap::_name = "Anon_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_damage = FragTrap::_damage;
	
	std::cout << "Kureiji Daiyamondo! [Diamond constructor]" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_type = "DI4M-TP";
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_hp;
	this->_ep = ScavTrap::_ep;
	this->_damage = FragTrap::_damage;

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

