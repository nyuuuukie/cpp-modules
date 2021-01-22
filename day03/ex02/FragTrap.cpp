/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/23 00:20:43 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

typedef std::string string;

FragTrap::FragTrap(void) : ClapTrap()
{
	_vaulthunterMinLimit = 25;
	std::cout << getQuoteName() << "Hey, best friend!" << std::endl;
}

FragTrap::FragTrap(string name) : ClapTrap(name, "FR4G-TP", 100, 100, 100, 100, 1, 30, 20, 5)  
{
	FragTrap();
}

FragTrap::~FragTrap(void)
{
	std::cout << getQuoteName() << "Alaka-ZAM!" << std::endl;
	std::cout << "*BOOOM*" << std::endl;
}

FragTrap::FragTrap(FragTrap const & other)
{
	*this = other;
}

FragTrap & FragTrap::operator=(FragTrap const & other)
{
	ClapTrap::operator=(other);
	_vaulthunterMinLimit = other._vaulthunterMinLimit;
	return *this;
}

const string  FragTrap::getQuoteName(void) const
{
	return "[FR4G-TP " + this->_name + "] : ";
}

int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int index = 0;
	int damageGiven = 0;
	float damagesCoeff[] = {1.3, 1.5, 1.7, 1.9, 2.1};
	
	string attacks[] = {"HIGH VOLTAGE",
						"THERMONUCLEAR BOMB",
						"ENERGY STORM",
						"DANCE OF BLADES",
						"ULTIMATE SUNLIGHT STREAM"
	};

	if (_ep >= _vaulthunterMinLimit)
	{
		_ep -= _vaulthunterMinLimit;
		
		index = rand() % 5;
		damageGiven = static_cast<int>(_rangedDamage * damagesCoeff[index]);
		printAttack(target, attacks[index], damageGiven);
	}
	else
	{
		std::cout << getQuoteName() << "Out of energy!" << std::endl;
	}
	return (damageGiven);
}
 