#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Anon")
{
	_hp = FragTrap::__hp__;
	_ep = FragTrap::__ep__;
	_damage = FragTrap::__dmg__;
	_type = "FR4G-TP";

	std::cout << getInfo() << " Gotcha! [Frag constructor]" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	_hp = FragTrap::__hp__;
	_ep = FragTrap::__ep__;
	_damage = FragTrap::__dmg__;
	_type = "FR4G-TP";
	std::cout << getInfo() << " Gotcha! [Frag constructor]" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << getInfo() << " deactivated! [Frag destructor]" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other)
{
	*this = other;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
	if (this != &other) {
		std::cout << "Cloning " << other._name;
		if (this->_name != "") {
			std::cout << " into " << this->_name;
		} else {
			std::cout << "...";
		}
		std::cout << " [Frag level]" << std::endl;

		this->ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys(void) const {
	std::cout << getInfo() << " HI FIVE! ^_^/ \\^_^" << std::endl;
}
