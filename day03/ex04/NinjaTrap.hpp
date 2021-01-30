/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:35:06 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 13:13:38 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

typedef std::string string;

class NinjaTrap : virtual public ClapTrap
{
	public:
	
		NinjaTrap(void);
		virtual ~NinjaTrap(void);

		NinjaTrap(string name);
		NinjaTrap(const NinjaTrap & other);
		NinjaTrap & operator=(const NinjaTrap & other);
	 	
		void	ninjaShoebox(FragTrap & frag);
		void	ninjaShoebox(ScavTrap & scav);
		void	ninjaShoebox(ClapTrap & clap);
		void	ninjaShoebox(NinjaTrap & ninja); 
};