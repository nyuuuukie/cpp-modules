#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	_announceText = "BraiiiiiiinnnzzzZ...";
	std::cout << "Constructor called" << std::endl;
}

Zombie::Zombie(void)
{
	_announceText = "* Silence *";
	std::cout << "Destructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called" << std::endl;
}

void Zombie::setAnnounceText(std::string text)
{
	this->_announceText = text;
}

void Zombie::announce(void) const
{
	std::cout << "[ " + _name + " ]: ";
	std::cout << _announceText << std::endl;
}
