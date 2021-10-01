#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) 
{
	ScavTrap droy("Droy");
	ScavTrap droy2("Drix");

	droy = droy2;

	droy.beRepaired(100);
	droy.takeDamage(40);
	droy.takeDamage(40);

	droy.guardGate();
	droy.attack("Robox");
	droy.takeDamage(150);

	return (0);
}
