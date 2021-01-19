/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:40 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/19 05:27:27 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <stdlib.h>

int attack(FragTrap & first, FragTrap & second)
{
	int number = rand () % 3;
	
	int damage;

	if (number == 0)
		damage = first.meleeAttack(second.getName());
	if (number == 1)
		damage = first.rangedAttack(second.getName());
	if (number == 2)
		damage = first.vaulthunter_dot_exe(second.getName());
	second.takeDamage(damage);
	first.beRepaired(damage / 10);
}

void	win(FragTrap & winner, FragTrap & loser)
{
	std::cout << "CHAMPION [FR4G-TP " << winner.getName() << "] smashed ";
	std::cout << loser.getName() << "!!!" << std::endl;	
}

int startBattle(FragTrap & first, FragTrap & second)
{
	while (first.getHP() && second.getHP())
	{
		if (rand () % 2)
			attack(first, second);		
		else
			attack(second, first);
	}
	if (first.getHP())
		win(first, second);
	else
		win(first, second);
	return (0);
}

int main(void)
{
	FragTrap firstTrap("Drillbit");
	FragTrap secondTrap("Iciqtron");

	startBattle(firstTrap, secondTrap);
	return (0);
}
