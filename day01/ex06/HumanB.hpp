/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:31:02 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 08:30:53 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(void);
		~HumanB(void);
		HumanB(std::string name);
		HumanB(std::string name, Weapon& weapon);
		void attack(void);
		void setWeapon(Weapon& weapon);
	
	private:
		std::string _name;
		Weapon* _weapon;
};