/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:40 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/22 23:34:23 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#include <cstdlib>
#include <ctime>

void attackFragTrap(FragTrap & frag, ScavTrap & scav)
{
	int number = rand () % 3;
	int damage = 0;

	if (number == 0)
		damage = frag.meleeAttack(scav.getName());
	if (number == 1)
		damage = frag.rangedAttack(scav.getName());
	if (number == 2)
		damage = frag.vaulthunter_dot_exe(scav.getName());
	scav.takeDamage(damage);
	frag.beRepaired(damage / 2);
}

void attackScavTrap(ScavTrap & scav, FragTrap & frag)
{
	int number = rand () % 3;
	int damage = 0;

	if (number == 0)
		damage = scav.meleeAttack(frag.getName());
	if (number == 1)
		damage = scav.rangedAttack(frag.getName());
	else
	{
		scav.challengeNewcomer();
		scav.beRepaired(5);
	}
	
	if (damage != 0)
	{
		frag.takeDamage(damage);
		scav.beRepaired(damage / 2);
	}
}

void	win(const string & winner, const string & loser)
{
	std::cout << "CHAMPION [" << "\033[32m" << winner;
	std::cout << "\033[0m" << "] smashed ";
	std::cout << loser << "!!!" << std::endl;	
}

int startBattle(FragTrap & frag, ScavTrap & scav)
{
	while (frag.getHP() > 0 && scav.getHP() > 0) 
	{
		if (rand () % 2)
			attackFragTrap(frag, scav);
		else
			attackScavTrap(scav, frag);		
	}
	if (frag.getHP())
		win(frag.getName(), scav.getName());
	else
		win(scav.getName(), frag.getName());
	return (0);
}

int main(void) 
{
	srand(time(0));

	FragTrap frag("Cybel");
	ScavTrap scav("Iztron");

	std::cout << "------------------------------START BATTLE------------------------------" << std::endl;
	startBattle(frag, scav);
	std::cout << "------------------------------------------------------------------------" << std::endl;
	return (0);
}
