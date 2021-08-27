#include "Zombie.hpp"

std::string getName(void)
{
	const int length = 5;

	std::string names[length] = {
		"John",	"Kate", "Luke", "Liam", "Noah",
	};
	return names[rand() % length];
}

int main(void)
{
	Zombie *zombie = newZombie(getName());
	zombie->setAnnounceText("Braining on the heap...");
	zombie->announce();

	delete zombie;

	randomChump(getName());
	
	return 0;
}
