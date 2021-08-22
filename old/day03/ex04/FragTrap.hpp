/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 13:23:11 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

typedef std::string string;

class FragTrap : virtual public ClapTrap
{
	public:
	
		FragTrap(void);
		FragTrap(FragTrap const & other);	
		FragTrap(string name);
		virtual ~FragTrap(void);
		
		FragTrap & operator=(FragTrap const & other);
		
		static const int attacksCount = 5;
		static string attacks[attacksCount];
		static float vaultHunterDamagesCoeff[attacksCount];
		
		int	vaulthunter_dot_exe(std::string const & target);

	private:
		int _vaulthunterMinLimit;
};
