/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:21:06 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:53:17 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void	randomChump(ZombieEvent &zombieEvent, std::string text)
{
	std::string name;
	
	name = Zombie::getRandomName();

	Zombie *zombiePtr = zombieEvent.newZombie(name);
	zombiePtr->setAnnounceText(text);
	zombiePtr->announce();

	delete zombiePtr;
}

int main(void)
{
	srand(time(0));

	ZombieEvent zombieEvent;

	zombieEvent.setZombieType("Blade runner");
	randomChump(zombieEvent, "Destroy all replicants.");
	zombieEvent.setZombieType("Dalek");
	randomChump(zombieEvent, "I love eggs <3");
	zombieEvent.setZombieType("Goose");
	randomChump(zombieEvent, "Kill all humans!");
	
	return (0);
}