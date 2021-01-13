/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:30:07 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 10:50:01 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
	this->_name = name;
	std::cout << _name + " created." << std::endl;
}

HumanA::HumanA(void) : _weapon(*new Weapon)
{
	this->_name = "<Default name>";
	std::cout << _name + " created." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << _name + " destroyed." << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << _name + " attacks with his " + _weapon.getType() << std::endl;
}