/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:26:07 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/22 22:49:36 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

typedef std::string string;

void	ClapTrap::init(string name)
{
	_name = name;
	_type = "CL4P-TP"; 
	_hp = 100;
	_ep = 100;
	_level = 1;
	_meleeDamage = 30;
	_rangedDamage = 20;
	_armorDamageReduction = 5;
}

ClapTrap::ClapTrap(void) : _max_hp(100), _max_ep(100) 
{
	init("Clu");
	std::cout << _type << " " << _name << " turned on." << std::endl;
}

ClapTrap::ClapTrap(string name)  : _max_hp(100), _max_ep(100)
{
	init(name);
	std::cout << _type << " " << _name << " turned on." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _type << " " << _name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & other)
{
	std::cout << "Cloning " << other._name << " ..." << std::endl;
	*this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other)
{
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_name = other._name;
	this->_type = other._type;
	this->_level = other._level;
	this->_max_ep = other._max_ep;
	this->_max_hp = other._max_hp;
	this->_meleeDamage = other._meleeDamage;
	this->_rangedDamage = other._rangedDamage;
	this->_armorDamageReduction = other._armorDamageReduction;

	return *this;
}

int ClapTrap::getHP(void) const
{
	return this->_hp;
}

const string & ClapTrap::getName(void) const
{
	return this->_name;
}

int ClapTrap::rangedAttack(std::string const & target)
{
	if (_ep >= _rangedDamage)
	{
		_ep -= _rangedDamage;
		printAttack(target, "ranged", _rangedDamage);
		return _rangedDamage;
	}
	return (0);
}

int ClapTrap::meleeAttack(std::string const & target)
{
	printAttack(target, "melee", _meleeDamage);
	return (_meleeDamage);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int damage = amount - _armorDamageReduction;
	_hp = _hp - damage > 0 ? _hp - damage : 0; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int possibleHP = _hp + amount;
	_hp = possibleHP > _max_hp ? _max_hp : possibleHP; 
}

void	ClapTrap::printAttack(string const & target, string const attack, int damage) const
{
	std::cout << _type << " " << _name << " ";
	std::cout << "used "<< attack << " attack on " << target << " ";
	std::cout << "causing " << damage << " ";
	std::cout << "points of damage!" << std::endl;
}