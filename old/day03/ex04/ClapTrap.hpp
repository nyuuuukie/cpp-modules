/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:26:16 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 14:10:35 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class ClapTrap
{
	public:
	
		ClapTrap(void);
		ClapTrap(string const & name);
		virtual ~ClapTrap(void);
		
		ClapTrap(ClapTrap const & other);	
		
		ClapTrap & operator=(ClapTrap const & other);
		
		void	init(string name);
		int		rangedAttack(std::string const & target);
		int		meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printAttack(string const & target, string const attack, int damage) const;

		//Getters and setters
		int				getHP(void) const;
		const string & 	getName(void) const;
		const string & 	getType(void) const;
		const string 	getQuoteName(void) const;
	
	protected:

		int _hp;
		int _ep;
		int _level;
		int _max_hp;
		int _max_ep;
		string _name;
		string _type;
		int _meleeDamage;
		int _rangedDamage;
		int _armorDamageReduction;

};
