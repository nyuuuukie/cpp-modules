/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:40 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 14:48:02 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

#include <cstdlib>
#include <ctime>

int specialAttack(ClapTrap *first, ClapTrap *second)
{
	int damage = 0;

	if (first->getType() == "FR4G-TP")
		damage = dynamic_cast<FragTrap *>(first)->vaulthunter_dot_exe(second->getName());
	else if (first->getType() == "SC4V-TP")
	{
		dynamic_cast<ScavTrap *>(first)->challengeNewcomer();
		dynamic_cast<ScavTrap *>(first)->beRepaired(5);
	}
	else if (first->getType() == "NINJA-TP")
	{
		dynamic_cast<NinjaTrap *>(first)->ninjaShoebox(*second);
		dynamic_cast<NinjaTrap *>(first)->beRepaired(8);
	}
	else if (first->getType() == "SUP3R-TP")
	{
		if (rand() % 2 == 1)
			damage = dynamic_cast<FragTrap *>(first)->vaulthunter_dot_exe(second->getName());
		else
		{
			dynamic_cast<NinjaTrap *>(first)->ninjaShoebox(*second);
			dynamic_cast<NinjaTrap *>(first)->beRepaired(8);
		}
	}
	else
		std::cout << "A HAVE NO SUPERPOWERS!" << std::endl;
	return (damage);
}

void attackClapTrap(ClapTrap *first, ClapTrap *second)
{
	int number = rand () % 10;
	int damage = 0;

	if (number < 4)
		damage = first->meleeAttack(second->getName());
	else if (number < 8)
		damage = first->rangedAttack(second->getName());
	else if (number == 8 || number == 9)
		damage = specialAttack(first, second);
	
	if (damage != 0)
	{
		second->takeDamage(damage);
		first->beRepaired(damage / 2);
	}
}

void	win(const string & winner, const string & loser)
{
	std::cout << "CHAMPION [" << "\033[32m" << winner;
	std::cout << "\033[0m" << "] smashed ";
	std::cout << loser << "!!!" << std::endl;	
}

int startBattle(ClapTrap & first, ClapTrap & second)
{
	while (first.getHP() > 0 && second.getHP() > 0) 
	{
		if (rand () % 2)
			attackClapTrap(&first, &second);
		else
			attackClapTrap(&second, &first);		
	}
	if (first.getHP())
		win(first.getName(), second.getName());
	else
		win(second.getName(), first.getName());
	return (0);
}

int main(void) 
{
	srand(time(0));

	FragTrap frag("Cybel");
	ScavTrap scav("Iztron");
	ClapTrap clap("Altron");
	NinjaTrap ninja("Uzamaki");
	SuperTrap super("Super");
	
	std::cout << "------------------------------START FIRST BATTLE------------------------------" << std::endl;
	startBattle(super, frag);
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	
	//std::cout << "------------------------------START SECOND BATTLE------------------------------" << std::endl;
	//startBattle(ninja, clap);
	//std::cout << "-------------------------------------------------------------------------------" << std::endl;

	//ninja.ninjaShoebox(frag);
	//ninja.ninjaShoebox(scav);
	//ninja.ninjaShoebox(clap);
	//ninja.ninjaShoebox(ninja);
	
	return (0);
}
