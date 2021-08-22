/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 11:08:56 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 13:54:44 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
	
typedef std::string string;

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
	
		SuperTrap(void);
		SuperTrap(string name);
		
		virtual ~SuperTrap(void);
		
		SuperTrap(const SuperTrap & other);
		SuperTrap & operator=(const SuperTrap & other);

		void	meleeAttack(std::string const &target);
    	void	rangedAttack(std::string const &target);
};