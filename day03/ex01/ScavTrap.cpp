/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/20 09:14:15 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

typedef std::string string;
		
void	ScavTrap::init(string name)
{
	_name = name;
	_hp = 100;
	_ep = 50;
	_level = 1;
	_meleeDamage = 20;
	_rangedDamage = 15;
	_armorDamageReduction = 5;
}

ScavTrap::ScavTrap(void) : _max_hp(100), _max_ep(50) 
{
	init("Default");
	std::cout << "[FR4G-TP " << _name << "] : Hey, best friend!" << std::endl;
}

ScavTrap::ScavTrap(string name)  : _max_hp(100), _max_ep(50)
{
	init(name);
	std::cout << "[FR4G-TP " << _name << "] : Let me teach you the ways of magic!";
	std::cout << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "[FR4G-TP " << _name << "] : ";
	std::cout << " Alaka-ZAM!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & other)
{
	std::cout << "Cloning " << other._name << " ..." << std::endl;
	*this = other;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_level = other._level;
	this->_max_ep = other._max_ep;
	this->_max_hp = other._max_hp;
	this->_meleeDamage = other._meleeDamage;
	this->_rangedDamage = other._rangedDamage;
	this->_armorDamageReduction = other._armorDamageReduction;
	
	return *this;
}

const string & ScavTrap::getName(void)
{
	return this->_name;
}

int	ScavTrap::getHP(void)
{
	return this->_hp;
}

void	ScavTrap::printAttack(string const & target, string const attack, int damage)
{
	std::cout << "FR4G-TP " << this->_name << " ";
	std::cout << "used "<< attack << " attack on " << target << " ";
	std::cout << "causing " << damage << " ";
	std::cout << "points of damage!" << std::endl;
}

int ScavTrap::rangedAttack(std::string const & target)
{
	if (_ep >= _rangedDamage)
	{
		_ep -= _rangedDamage;
		printAttack(target, "ranged", _rangedDamage);
		return _rangedDamage;
	}
	return (0);
}

int ScavTrap::meleeAttack(std::string const & target)
{
	printAttack(target, "melee", _meleeDamage);
	return (_meleeDamage);
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	int damage = amount - _armorDamageReduction;
	_hp = _hp - damage > 0 ? _hp - damage : 0; 
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	int possibleHP = _hp + amount;
	_hp = possibleHP > _max_hp ? _max_hp : possibleHP; 
}

void ScavTrap::challengeNewcomer(void)
{

}
 