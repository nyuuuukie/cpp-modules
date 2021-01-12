/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:00:28 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/10 23:08:57 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type)
{
	_announceText = "Braaaaaains...";
	std::cout << "Constructor called" << std::endl;
}


Zombie::Zombie(void) : _name("<No name>"), _type("<No type>")
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

void	Zombie::announce(void)
{
	std::cout << "[" + _type + " " + _name + "]: ";
	std::cout << _announceText << std::endl; 
}
