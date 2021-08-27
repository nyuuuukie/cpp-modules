/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 05:58:44 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/13 07:24:13 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "First brain then human." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Destroy the brain!" << std::endl;
}

std::string Brain::itos(long long number)
{
	std::string hex = number / 16 != 0 ? itos(number / 16) : "";
	hex += number % 16 < 10 ? number % 16 + '0' : number % 16 - 10 + 'A';
	return hex;
}

std::string	Brain::identify(void)
{
	return "0x" + itos((long long)this);
}
