/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:29:34 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 10:37:26 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::Weapon(void)
{
	_type = "stick";
}

Weapon::~Weapon(void)
{
	std::cout << _type << " destroyed." << std::endl;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

const std::string &	Weapon::getType(void)
{
	return this->_type;
}