/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/23 00:59:30 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

typedef std::string string;

class ScavTrap : public ClapTrap
{
	public:
	
		ScavTrap(void);
		ScavTrap(ScavTrap const & other);	
		ScavTrap(string name);
		~ScavTrap(void);
		
		ScavTrap & operator=(ScavTrap const & other);
		
		void	challengeNewcomer(void) const;
};
