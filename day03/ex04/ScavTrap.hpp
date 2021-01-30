/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 13:13:23 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

typedef std::string string;

class ScavTrap : virtual public ClapTrap
{
	public:
	
		ScavTrap(void);
		ScavTrap(ScavTrap const & other);	
		ScavTrap(string name);
		virtual ~ScavTrap(void);
		
		ScavTrap & operator=(ScavTrap const & other);
		
		void	challengeNewcomer(void) const;
};
