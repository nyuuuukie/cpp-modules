/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:08:44 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/24 10:51:05 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void)
{
	_chosenType = Zombie::getRandomType();
	std::cout << "ZombieEvent constructor called" << std::endl;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "ZombieEvent destructor called" << std::endl;
}

void	ZombieEvent::setZombieType(std::string type)
{
	this->_chosenType = type;
}

Zombie*	ZombieEvent::newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name, _chosenType);
	return zombie;
}