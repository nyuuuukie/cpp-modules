/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 21:48:22 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/22 23:31:16 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

typedef std::string string;

class FragTrap : public ClapTrap
{
	public:
	
		FragTrap(void);
		FragTrap(FragTrap const & other);	
		FragTrap(string name);
		~FragTrap(void);
		
		FragTrap & operator=(FragTrap const & other);
		
		const string 	getQuoteName(void) const;
		int 			vaulthunter_dot_exe(std::string const & target);
		
	private:
		int _vaulthunterMinLimit;
};
