/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:19 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 14:15:43 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

typedef std::string string;

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "[Default frag constructor]" << std::endl;
	_vaulthunterMinLimit = 25;
}

FragTrap::FragTrap(string name) : ClapTrap(name)  
{
	_type = "FR4G-TP";
	_meleeDamage = 30;
	_rangedDamage = 20;
	_armorDamageReduction = 5;
	_vaulthunterMinLimit = 25;
	std::cout << this->getQuoteName() << "Hey, best friend!" << std::endl;
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

string FragTrap::attacks[FragTrap::attacksCount] = {
						"HIGH VOLTAGE",
						"THERMONUCLEAR BOMB",
						"ENERGY STORM",
						"DANCE OF BLADES",
						"ULTIMATE SUNLIGHT STREAM"
};

float FragTrap::vaultHunterDamagesCoeff[FragTrap::attacksCount] = {
						1.3, 1.5, 1.7, 1.9, 2.1
};
	
int FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int index = 0;
	int damageGiven = 0;
	
	if (_ep >= _vaulthunterMinLimit)
	{
		_ep -= _vaulthunterMinLimit;
		index = rand() % attacksCount;
		damageGiven = static_cast<int>(_rangedDamage * vaultHunterDamagesCoeff[index]);
		printAttack(target, attacks[index], damageGiven);
	}
	else
	{
		std::cout << getQuoteName() << "Out of energy!" << std::endl;
	}
	return (damageGiven);
}
 