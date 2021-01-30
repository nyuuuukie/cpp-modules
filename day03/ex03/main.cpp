/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:40 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 10:54:14 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

#include <cstdlib>
#include <ctime>

int specialAttack(ClapTrap *first, ClapTrap *second)
{
	int damage = 0;

	if (first->getType() == "FR4G-TP")
		damage = ((FragTrap *)first)->vaulthunter_dot_exe(second->getName());
	else if (first->getType() == "SC4V-TP")
	{
		((ScavTrap *)first)->challengeNewcomer();
		((ScavTrap *)first)->beRepaired(5);
	}
	else if (first->getType() == "NINJA-TP")
	{
		((NinjaTrap *)first)->ninjaShoebox(*second);
		((NinjaTrap *)first)->beRepaired(8);
	}
	else
		std::cout << "A HAVE NO SUPERPOWERS!" << std::endl;
	return (damage);
}

void attackClapTrap(ClapTrap *first, ClapTrap *second)
{
	int number = rand () % 3;
	int damage = 0;

	if (number == 0)
		damage = first->meleeAttack(second->getName());
	else if (number == 1)
		damage = first->rangedAttack(second->getName());
	else if (number == 2)
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
	NinjaTrap ninja("Uzamaki");
	ClapTrap clap;

	std::cout << "------------------------------START FIRST BATTLE------------------------------" << std::endl;
	startBattle(frag, scav);
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	
	std::cout << "------------------------------START SECOND BATTLE------------------------------" << std::endl;
	startBattle(ninja, clap);
	std::cout << "-------------------------------------------------------------------------------" << std::endl;

	//ninja.ninjaShoebox(frag);
	//ninja.ninjaShoebox(scav);
	//ninja.ninjaShoebox(clap);
	//ninja.ninjaShoebox(ninja);
	
	return (0);
}
