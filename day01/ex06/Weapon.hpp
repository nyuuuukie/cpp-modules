/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 07:29:42 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 10:36:22 by mhufflep         ###   ########.fr       */
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
		const std::string& getType(void);
		void setType(std::string type);

	private:
		std::string _type;
};
