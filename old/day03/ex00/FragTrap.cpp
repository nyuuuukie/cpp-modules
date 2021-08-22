/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/20 09:12:57 by mhufflep         ###   ########.fr       */
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
	this->_armorDamageReduction = other._armorDamageReduction;
	
	return *this;
}

const string & FragTrap::getName(void)
{
	return this->_name;
}

int	FragTrap::getHP(void)
{
	return this->_hp;
}

void	FragTrap::printAttack(string const & target, string const attack, int damage)
{
	std::cout << "FR4G-TP " << this->_name << " ";
	std::cout << "used "<< attack << " attack on " << target << " ";
	std::cout << "causing " << damage << " ";
	std::cout << "points of damage!" << std::endl;
}

int FragTrap::rangedAttack(std::string const & target)
{
	if (_ep >= _rangedDamage)
	{
		_ep -= _rangedDamage;
		printAttack(target, "ranged", _rangedDamage);
		return _rangedDamage;
	}
	return (0);
}

int FragTrap::meleeAttack(std::string const & target)
{
	printAttack(target, "melee", _meleeDamage);
	return (_meleeDamage);
}

void	FragTrap::takeDamage(unsigned int amount)
{
	int damage = amount - _armorDamageReduction;
	_hp = _hp - damage > 0 ? _hp - damage : 0; 
}

void	FragTrap::beRepaired(unsigned int amount)
{
	int possibleHP = _hp + amount;
	_hp = possibleHP > _max_hp ? _max_hp : possibleHP; 
}

int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int r = 0;
	int damageGiven = 0;
	float damagesCoeff[] = {1.3, 1.5, 1.7, 1.9, 2.1};
	string attacks[] = {"HIGH VOLTAGE", "THERMONUCLEAR BOMB", "ENERGY STORM", "DANCE OF BLADES", "ULTIMATE SUNLIGHT STREAM"};
	if (_ep >= _vaulthunterMinLimit)
	{
		_ep -= _vaulthunterMinLimit;
		r = rand() % 5;
		printAttack(target, attacks[r], static_cast<int>(_rangedDamage * damagesCoeff[r]));
	}
	else
	{
		std::cout << "[FR4G-TP]: Out of energy!" << std::endl;
	}
	return (damageGiven);
}
 