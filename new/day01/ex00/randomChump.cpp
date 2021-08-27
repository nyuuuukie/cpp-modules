#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.setAnnounceText("Braining on the stack...");
	zombie.announce();
}
