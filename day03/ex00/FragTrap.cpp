/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/19 06:09:58 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

typedef std::string string;

void	FragTrap::init(string name)
{
	_name = name;
	_hp = 100;
	_ep = 100;
	_level = 1;
	_meleeDamage = 30;
	_rangedDamage = 20;
	_armorDamageReduction = 5;
	_rangedDamageMinLimit = 10;
	_vaulthunterMinLimit = 25;
}

FragTrap::FragTrap(void) : _max_hp(100), _max_ep(100) 
{
	init("Default");
	std::cout << "[FR4G-TP " << _name << "] : Hey, best friend!" << std::endl;
}

FragTrap::FragTrap(string name)  : _max_hp(100), _max_ep(100)
{
	init(name);
	std::cout << "[FR4G-TP " << _name << "] : Let me teach you the ways of magic!";
	std::cout << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "[FR4G-TP " << _name << "] : ";
	std::cout << " Alaka-ZAM!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other)
{
	std::cout << "Cloning " << other._name << " ..." << std::endl;
	*this = other;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
	this->_name = other._name;
	this->_hp = other._hp;
	this->_ep = other._ep;
	this->_level = other._level;
	this->_max_ep = other._max_ep;
	this->_max_hp = other._max_hp;
	this->_meleeDamage = other._meleeDamage;
	this->_rangedDamage = other._rangedDamage;
	this->_vaulthunterMinLimit = other._vaulthunterMinLimit;
	this->_rangedDamageMinLimit = other._rangedDamageMinLimit;
	this->_armorDamageReduction = other._armorDamageReduction;
	
	return *this;
}

const string & FragTrap::getName(void)
{
	return this->_name;
}

void	FragTrap::printAttack(string const & target, string const attack)
{
	std::cout << "FR4G-TP " << this->_name << " ";
	std::cout << "used "<< attack << " attack on " << target << " ";
	std::cout << "causing " << _rangedDamage << " ";
	std::cout << "points of damage!" << std::endl;
}

int FragTrap::rangedAttack(std::string const & target)
{
	if (_ep >= _rangedDamageMinLimit)
	{
		_ep -= _rangedDamageMinLimit;
		printAttack(target, "ranged");
		return _rangedDamage;
	}
	return (0);
}

int FragTrap::meleeAttack(std::string const & target)
{
	printAttack(target, "melee");
	return (_meleeDamage);
}

int FragTrap::highVoltage(std::string const & target)
{
	if (_ep >= _rangedDamageMinLimit)
	{
		_ep -= _rangedDamageMinLimit;
		printAttack(target, "HIGH VOLTAGE");
		return ;
	}
	return (0);
}

int FragTrap::highVoltage(std::string const & target)
{
	printAttack(target, "HIGH VOLTAGE");
}


int FragTrap::highVoltage(std::string const & target)
{
	printAttack(target, "HIGH VOLTAGE");
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int damage = amount - _armorDamageReduction;
	_hp -= damage > 0 ? damage : 0;	
}

void	FragTrap::beRepaired(unsigned int amount)
{
	int possibleHP = _hp + amount;
	_hp = possibleHP > _max_hp ? _max_hp : possibleHP; 
}

int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int damageGiven = 0;
	if (_ep >= _vaulthunterMinLimit)
	{
		_ep -= _vaulthunterMinLimit;
		//RANDOM ATTACK
		rand() % 5;
	}
	else
	{
		std::cout << "[FR4G-TP]: Out of energy!" << std::endl;
	}
	return (damageGiven);
}