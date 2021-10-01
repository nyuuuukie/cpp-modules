#include "ClapTrap.hpp"

int main(void) 
{
	ClapTrap robox("Robox");
	
	robox.beRepaired(50);
	robox.beRepaired(50);

	robox.takeDamage(10);
	robox.takeDamage(30);

	robox.beRepaired(50);

	robox.attack("Droy");
	robox.takeDamage(150);

	{
		ClapTrap anon;
	
		anon.beRepaired(50);
		anon.beRepaired(50);

		anon.takeDamage(10);
		anon.takeDamage(30);

		anon.beRepaired(50);

		anon.attack("Droy2");
		anon.takeDamage(150);

		ClapTrap anon2(anon);
		anon2.attack("Anonymous");

		anon2 = robox;
	}
	
	return (0);
}
