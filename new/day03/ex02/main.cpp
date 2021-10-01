#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) 
{
	FragTrap quox("Quox");
	FragTrap quox2("Quox2");

	quox = quox2;

	quox.beRepaired(100);
	quox.takeDamage(40);
	quox.takeDamage(40);

	quox.highFivesGuys();
	quox.attack("Robox");
	quox.takeDamage(150);

	return (0);
}
