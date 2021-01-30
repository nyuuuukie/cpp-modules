/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:35:03 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 10:38:54 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

typedef std::string string;

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	std::cout << "THEN PAY WITH YOUR BLOOD!" << std::endl;
}

NinjaTrap::NinjaTrap(string name) : ClapTrap(name, "NINJA-TP", 60, 60, 120, 120, 1, 60, 5, 0)
{
	NinjaTrap();
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << getQuoteName() << "Turtles kicked my ass!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & other)
{
	*this = other;
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & other)
{
	ClapTrap::operator=(other);
	return *this;
}

void	NinjaTrap::ninjaShoebox(FragTrap & frag)
{
	std::cout << frag.getQuoteName() << "*MEMORY FRAGMENTATION STARTED...*" << std::endl;	
}

void	NinjaTrap::ninjaShoebox(ScavTrap & scav)
{
	std::cout << scav.getQuoteName() << "I AM A SCAV TRAP, NOT A TRASH CAN!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & clap)
{
	std::cout << clap.getQuoteName() << "I AM THE ORIGIN, MAAAN!" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & ninja)
{
	std::cout << ninja.getQuoteName() << "WHERE IS MY FRUITS?! (NIHONGO GA WAKARUKA?)" << std::endl;
}