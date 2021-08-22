/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 20:28:43 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/30 22:53:55 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

typedef std::string string;

Peon::Peon(string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl; 
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl; 
}

void Peon::getPolymorphed(void) const
{
	std::cout << getName() << " has been turned into a pink pony!" << std::endl;
}
