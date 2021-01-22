/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 00:35:06 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/23 01:21:58 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

typedef std::string string;

class NinjaTrap : public ClapTrap
{
	public:
	
		NinjaTrap(void);
		~NinjaTrap(void);

		NinjaTrap(string name);
		NinjaTrap(const NinjaTrap & other);
		NinjaTrap & operator=(const NinjaTrap & other);
	 	
		void	ninjaShoebox(FragTrap & const frag);
		void	ninjaShoebox(ScavTrap & const scav);
		void	ninjaShoebox(ClapTrap & const clap);
		void	ninjaShoebox(NinjaTrap & const ninja); 
};