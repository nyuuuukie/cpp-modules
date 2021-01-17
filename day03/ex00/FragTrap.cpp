/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/16 22:59:29 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

typedef std::string string;

FragTrap::FragTrap(void)
{
	
}

FragTrap::FragTrap(string name)
{
	this->_name = name;
}

FragTrap::~FragTrap(void)
{
	
}

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << this->_name << " ";
	std::cout << "attacks " << target << " ";
	std::cout << "at range, causing " << 12 << " ";
	std::cout << "points of damage!" << std::endl;
}