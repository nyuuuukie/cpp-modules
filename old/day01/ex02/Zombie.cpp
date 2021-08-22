/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:00:28 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/12 06:50:49 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string Zombie::getRandomName(void)
{
	const int length = 13;
	long long index;
	std::string names[length] = {
						"John",
						"Kate",
						"Luke",
						"Liam",
						"Noah",
						"Emma",
						"Sally",
						"James",
						"Amanda",
						"Olivia",
						"Sophia",
						"Oliver",
						"William"
	};
	
	index = rand() % length;
	return names[index];
}

std::string Zombie::getRandomType(void)
{
	const int length = 4;
	long long index;
	std::string types[length] = {
						"Brainless",
						"Skinny",
						"Blessed",
						"Stinky",
	};
	
	index = rand() % length;
	return types[index];
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	_announceText = "Braaaaaains...";
	std::cout << "Constructor called" << std::endl;
}

Zombie::Zombie(void)
{
	_announceText = "<No announce>";
	std::cout << "Destructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called" << std::endl;
}

void	Zombie::setAnnounceText(std::string text)
{
	this->_announceText = text; 
}

void	Zombie::announce(void) const
{
	std::cout << "[" + _type + " " + _name + "]: ";
	std::cout << _announceText << std::endl; 
}
