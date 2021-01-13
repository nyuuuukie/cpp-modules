/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:30:21 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 10:54:40 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << name + " created." << std::endl;
}

HumanB::HumanB(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << _name + " attacks with his " + _weapon->getType() << std::endl;
}