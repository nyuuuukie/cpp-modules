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
	srand(time(0));

	const int count = 10;
	Zombie *horde = zombieHorde(count, getName());

	for (int i = 0; i < count; i++)
		horde[i].announce();

	//(*(horde + count - 1)).setAnnounceText("I am a smart one");
	//(*(horde + count - 1)).announce();

	delete[] horde;
	return 0;
}
