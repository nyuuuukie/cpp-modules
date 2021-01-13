/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:30:14 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 10:43:24 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(void);
		~HumanA(void);
		HumanA(std::string name, Weapon& weapon);
		void attack(void);
	
	private:
		std::string _name;
		Weapon& _weapon;
};