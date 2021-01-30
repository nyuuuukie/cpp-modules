/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:08:54 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 14:41:39 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void)
{
	std::cout << "NINJA-SUPER-FRAG-ULTRA-MEGA-EXTRA TRAP CREATED!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << getQuoteName() << "TRAP WAS TRAPPED!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

SuperTrap::SuperTrap(string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->_type = "SUP3R-TP";
	this->_hp = this->FragTrap::_hp;
	this->_max_hp = this->FragTrap::_max_hp;
	this->_ep = this->FragTrap::_ep;
	this->_max_ep = this->FragTrap::_max_ep;
	this->_meleeDamage = this->NinjaTrap::_meleeDamage;
	this->_rangedDamage = this->FragTrap::_rangedDamage;
	this->_armorDamageReduction = this->FragTrap::_armorDamageReduction;
}

SuperTrap::SuperTrap(const SuperTrap & other)
{
	*this = other;
}

SuperTrap & SuperTrap::operator=(const SuperTrap & other)
{
	FragTrap::operator=(other);
	return (*this);
}

void	SuperTrap::meleeAttack(std::string const &target)
{
	NinjaTrap::rangedAttack(target);
}

void	SuperTrap::rangedAttack(std::string const &target)
{
	FragTrap::rangedAttack(target);
}