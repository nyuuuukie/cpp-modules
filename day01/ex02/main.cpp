/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:21:06 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/11 00:32:58 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string getRandomName()
{
	const int length = 13;
	long long index;
	std::string names[length] = {
						"John",
						"Kate",
						"Luke",
						"Liam",
						"Noah",
						"Emma",
						"Sally",
						"James",
						"Amanda",
						"Olivia",
						"Sophia",
						"Oliver",
						"William"
	};
	
	index = rand() % length;
	return names[index];
}

void	randomChump(ZombieEvent &zombieEvent)
{
	std::string name;
	
	name = getRandomName();

	Zombie *zombiePtr = zombieEvent.newZombie(name);
	zombiePtr->setAnnounceText("All those moments will be lost in time.");
	zombiePtr->announce();

	delete zombiePtr;
}

int main(void)
{
	srand(time(0));

	ZombieEvent zombieEvent;

	zombieEvent.setZombieType("Replicant");
	randomChump(zombieEvent);
	zombieEvent.setZombieType("Dalek");
	randomChump(zombieEvent);
	zombieEvent.setZombieType("Missix");
	randomChump(zombieEvent);
	
	return (0);
}