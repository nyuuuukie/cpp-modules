/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:29:18 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 23:04:09 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

typedef std::string string;

Victim::Victim(string name)
{
	_name = name;
	std::cout << "Some random victim called ";
	std::cout << _name << " just appeared!" << std::endl; 
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _name;
	std::cout << " just died for no apparent reason!" << std::endl; 
}

string Victim::getName(void) const
{
	return this->_name;
}

void Victim::getPolymorphed(void) const
{
	std::cout << getName() << " has been turned into a cute little sheep!" << std::endl;
}
	
std::ostream & operator<<(std::ostream & out, const Victim & Victim)
{
	out << "I'm " << Victim.getName() << " and I like otters!" << std::endl;
	return out;
}
