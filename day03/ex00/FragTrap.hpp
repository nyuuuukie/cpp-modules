/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/16 22:59:50 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class FragTrap
{
	public:
	
		FragTrap(void);
		FragTrap(string name);
		~FragTrap(void);
		
		void rangedAttack(std::string const & target)
		void meleeAttack(std::string const & target)
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
	private:
		int _hp; //(100)
		int _max_hp;// (100)
		int _ep; //(100)
		int _max_ep; // (100)
		int _level; // (1)
		string _name; //(Parameter of constructor)
		int _meleeDamage; //(30)
		int _rangedDamage; //(20)
		int _armorDamageReduction; //(5)
};
