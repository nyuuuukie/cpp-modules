#include "Zombie.hpp"
#include <ctime>

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
	srand(time(0));

	const int count = 10;
	Zombie *horde = zombieHorde(count, getName());

	for (int i = 0; i < count; i++)
		horde[i].announce();
	
	delete [] horde;

	return 0;
}
