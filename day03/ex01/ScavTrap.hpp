/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/20 09:14:29 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class ScavTrap
{
	public:
	
		ScavTrap(void);
		ScavTrap(ScavTrap const & other);	
		ScavTrap(string name);
		~ScavTrap(void);
		
		ScavTrap & operator=(ScavTrap const & other);
		
		void	init(string name);
		int		rangedAttack(std::string const & target);
		int		meleeAttack(std::string const & target);
		void	challengeNewcomer(void);
		void	printAttack(string const & target, string const attack, int damage);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
		//GETTERS AND SETTERS
		int				getHP(void);
		const string & 	getName(void);

	private:

		int _hp;
		int _ep;
		int _level;
		int _max_hp;
		int _max_ep;
		string _name;
		int _meleeDamage;
		int _rangedDamage;
		int _armorDamageReduction;
};
