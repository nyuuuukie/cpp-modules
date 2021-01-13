/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:29:42 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 08:31:14 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
	public:
		Weapon(void);
		~Weapon(void);
		Weapon(std::string type);
		std::string const & getType(void) const;
		void setType(std::string type);

	private:
		std::string _type;
};
