/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:27:56 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 23:02:24 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

typedef std::string string;

Sorcerer::Sorcerer(string name, string title)
{
	_name = name;
	_title = title;
	std::cout << _name << ", " << _title << ", is born!" << std::endl; 
}

Sorcerer::~Sorcerer(void)
{
	std::cout << _name << ", " << _title << ", ";
	std::cout << "is dead. Consequences will never be the same!" << std::endl; 
}

Sorcerer::Sorcerer(const Sorcerer & other)
{
	*this = other;
}

Sorcerer & Sorcerer::operator=(const Sorcerer & other)
{
	this->_name = other._name;
	this->_title = other._title;
	return *this;
}

string Sorcerer::getName(void) const
{
	return this->_name;
}

string Sorcerer::getTitle(void) const
{
	return this->_title;
}

void Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

std::ostream& operator<<(std::ostream & out, const Sorcerer& sorcerer)
{
	out << "I am " << sorcerer.getName() << ", ";
	out << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
	return out;
}

