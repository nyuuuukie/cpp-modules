#include "Zombie.hpp"
#include <ctime>
#include <cstdlib>

std::string getName(void)
{
	const int length = 5;

	std::string names[length] = {
		"John",
		"Kate",
		"Luke",
		"Liam",
		"Noah",
	};
	return names[rand() % length];
}

int main(void)
{
	//Allocated on the heap
	Zombie *zombie = newZombie(getName());

	//zombie->setAnnounceText("Braining on the heap...");
	zombie->announce();
	delete zombie;

	//Allocated on the stack
	randomChump(getName());

	return 0;
}
