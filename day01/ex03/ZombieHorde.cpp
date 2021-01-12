/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:01:29 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:47:01 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int amount) : _amountOfZombies(amount)
{
	_zombies = new Zombie[amount];

	std::cout << "> ";
	std::cout << COLOR_GREEN << "The world is threatened by a horde of ";
	std::cout << _amountOfZombies << " zombies!" << COLOR_RESET << std::endl;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _zombies;

	std::cout << "> ";
	std::cout << COLOR_GREEN << "And now all zombies are dead. ";
	std::cout << "The world is saved." << COLOR_RESET << std::endl;
}

void	ZombieHorde::announce(void) const
{
	for (int i = 0; i < _amountOfZombies; i++)
	{
		_zombies[i].announce();
	}
}
