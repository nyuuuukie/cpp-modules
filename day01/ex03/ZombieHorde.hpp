/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:49:03 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 07:47:20 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Zombie.hpp"

class ZombieHorde
{
	public:

		ZombieHorde(int amount);
		~ZombieHorde(void);
		void announce(void) const;
	
	private:

		const int _amountOfZombies;
		const Zombie* _zombies;
};
