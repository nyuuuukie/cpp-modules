#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Anon")
{
	_hp = ScavTrap::__hp__;
	_ep = ScavTrap::__ep__;
	_damage = ScavTrap::__dmg__;
	_type = "SC4V-TP";
	std::cout << getInfo() << " Let me teach you! [Scav constructor]" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	_hp = ScavTrap::__hp__;
	_ep = ScavTrap::__ep__;
	_damage = ScavTrap::__dmg__;
	_type = "SC4V-TP";
	std::cout << getInfo() << " Let me teach you! [Scav constructor]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << getInfo() << " is out of lifetime! [Scav destructor]" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other)
{
	*this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	if (this != &other) {

		std::cout << "Cloning " << other._name;
		if (this->_name != "") {
			std::cout << " into " << this->_name;
		} else {
			std::cout << "...";
		}
		std::cout << " [Scav level]" << std::endl;

		this->ClapTrap::operator=(other);
	}

	return *this;
}

void ScavTrap::guardGate(void) const {
	std::cout << getInfo() << " Gatekeeper mode activated." << std::endl;
}
