/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:30:07 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 08:37:25 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA(std::string name, Weapon& weapon) : _name(name)
{
	_weapon = &weapon;
}

HumanA::HumanA(std::string name) : _name(name)
{
	std::cout << name + " created." << std::endl;
}

HumanA::HumanA(void)
{
	std::cout << _name + " created." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void	HumanA::attack(void)
{
	std::cout << _name + " attacks with his " + _weapon.getType() << std::endl;
}