#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hp(10), _ep(10), _damage(0), _type("CL4P-TP")
{
	_name = "Anon";
	std::cout << getInfo() << " created. [Clap constructor]" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : _hp(10), _ep(10), _damage(0), _type("CL4P-TP")
{
	_name = name;
	std::cout << getInfo() << " created. [Clap constructor]" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << getInfo() << " destroyed. [Clap destructor]" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Cloning " << other._name;

	if (this->_name != "") {
		std::cout << " into " << this->_name << std::endl;
	} else {
		std::cout << "..." << std::endl;
	}

	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & other)
{
	if (this != &other) {
		this->_hp = other._hp;
		this->_ep = other._ep;
		this->_name = other._name;
		this->_type = other._type;
		this->_damage = other._damage;
	}
	return *this;
}

int ClapTrap::getHP(void) const
{
	return this->_hp;
}

int ClapTrap::getEP(void) const
{
	return this->_ep;
}

const std::string ClapTrap::getName(void) const
{
	return this->_name;
}

const std::string ClapTrap::getInfo(void) const {
	std::string res = "[ ";
	
	res += "name:" + getName() + " ";
	res += "hp:" + Utils::itos(getHP(), 10) + " ";
	res += "ep:" + Utils::itos(getEP(), 10) + " ]";

	return res;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int newHP = _hp - amount;
	int newEP = _ep - amount / 10;

	_hp = newHP > 0 ? newHP : 0;
	_ep = newEP > 0 ? newEP : 0;

	std::cout << getInfo() << " losing " << amount << " hp!" << std::endl;
	std::cout << getInfo() << " losing " << amount / 10 << " ep!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	_hp += amount;
	_ep += amount / 2;

	std::cout << getInfo() << " recovering " << amount << " hp!" << std::endl;
	std::cout << getInfo() << " recovering " << amount / 10 << " ep!" << std::endl;
}

void	ClapTrap::attack(std::string const & target)
{
	std::cout << getInfo() << " ";
	std::cout << "attacks on " << target << " ";
	std::cout << "causing " << _damage << " ";
	std::cout << "points of damage!" << std::endl;
}
