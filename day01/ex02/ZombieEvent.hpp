/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:08:56 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/11 00:35:33 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string _chosenType;
		std::string _announceText;
		
	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		Zombie* newZombie(std::string name);
		void	setZombieType(std::string type);
};