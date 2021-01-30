/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 23:18:15 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 23:27:35 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

typedef std::string string;

class AWeapon
{
	private:
		
		string	_name;
		int		_damage;
		int		_apCost;

	public:
		
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();
		
		std::string & const getName() const;
		int getAPCost() const;
		int getDamage() const;
		
		virtual void attack() const = 0;
};
