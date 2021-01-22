/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/22 23:35:02 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

typedef std::string string;

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_type = "SC4V-TP";
	std::cout << getQuoteName() << " : " << std::endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)  
{
	ScavTrap();
}

ScavTrap::~ScavTrap(void)
{
	std::cout << getQuoteName() << ": Away with thee!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other)
{
	*this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	ClapTrap::operator=(other);
	return *this;
}

const string  ScavTrap::getQuoteName(void) const
{
	return "[SC4V-TP " + this->_name + "] ";
}

void ScavTrap::challengeNewcomer(void) const
{
	const int length = 5;
	string challenges[length] = {"FEED CRAZY KITTY WITH BANANAS",
								 "RIDE ON THE INTERSTELLAR SPACESHIP",
								 "GO INTO ANOTHER DIMENSION",
								 "CATCH A RAINBOW",
								 "DO IT! JUST DO IT!"
	};
	int i = rand() % length;

	std::cout << getQuoteName() << ": it's time to " << challenges[i] + "." << std::endl;
}
 