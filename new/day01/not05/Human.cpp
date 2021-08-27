/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 06:03:46 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 07:48:15 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void)
{
	std::cout << "Human was born!" << std::endl;
}

Human::~Human(void)
{
	std::cout << "Human is dead now." << std::endl;
}

std::string	Human::identify(void)
{
	return this->_brain.identify();
}

Brain&	Human::getBrain(void)
{
	return this->_brain;
}