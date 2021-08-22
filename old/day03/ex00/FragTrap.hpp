/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/20 09:12:33 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class FragTrap
{
	public:
	
		FragTrap(void);
		FragTrap(FragTrap const & other);	
		FragTrap(string name);
		~FragTrap(void);
		
		FragTrap & operator=(FragTrap const & other);
		
		void	init(string name);
		int		rangedAttack(std::string const & target);
		int		meleeAttack(std::string const & target);
		int		vaulthunter_dot_exe(std::string const & target);
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
		int _vaulthunterMinLimit;
		int _armorDamageReduction;
};
