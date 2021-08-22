/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:00:28 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/24 11:40:13 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

std::string	Zombie::getRandomName(void)
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

std::string	Zombie::getRandomType(void)
{
	const int length = 6;
	long long index;
	std::string types[length] = {
						"Brainless",
						"Mad",
						"Blessed",
						"Stinky",
						"Crazy",
						"Furious"
	};
	
	index = rand() % length;
	return types[index];
}

std::string	Zombie::getRandomAnnounce(void)
{
	const int length = 4;
	long long index;
	std::string phrases[length] = {
						"Braaaaaains...",
						"Destroy humanity!",
						"Dead or alive!",
						"I'm bringing sexy back...(yeah)",
	};
	
	index = rand() % length;
	return phrases[index];
}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	_announce = "Braaaaaains...";
	std::cout << "[" + _type + " " + _name + "]: " << _announce << std::endl;
}

Zombie::Zombie(void)
{
	_name = Zombie::getRandomName();
	_type = Zombie::getRandomType();
	_announce = Zombie::getRandomAnnounce();

	std::cout << _name + " is infected. -> zombies++" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _type + " " + _name + " was killed." << std::endl;
}

void	Zombie::setAnnounce(std::string text)
{
	this->_announce = text; 
}

void	Zombie::announce(void) const
{
	std::cout << "[" + _type + " " + _name + "]: ";
	std::cout << COLOR_BLUE << _announce << COLOR_RESET << std::endl;
}
