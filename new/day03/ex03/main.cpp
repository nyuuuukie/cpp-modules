#include "DiamondTrap.hpp"

int main(void) 
{
	DiamondTrap flux("Flux");
	DiamondTrap flux2("Flux2");

	flux = flux2;

	flux.beRepaired(100);
	flux.takeDamage(40);
	flux.takeDamage(40);

	flux.attack("Drix");

	flux.highFivesGuys();
	flux.guardGate();
	flux.whoAmI();

	flux.takeDamage(150);
	return (0);
}
