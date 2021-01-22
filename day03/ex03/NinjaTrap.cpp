/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:35:03 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/23 02:18:13 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

typedef std::string string;

NinjaTrap::NinjaTrap(void) : ClapTrap()
{
	std::cout << "I'm better than the fucking turtles!" << std::endl;
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

void	NinjaTrap::ninjaShoebox(FragTrap & const frag)
{
	std::cout << getQuoteName() << "" << std::endl;	
}

void	NinjaTrap::ninjaShoebox(ScavTrap & const scav)
{
	std::cout << getQuoteName() << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & const clap)
{
	std::cout << getQuoteName() << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap & const ninja)
{
	std::cout << getQuoteName() << std::endl;
}