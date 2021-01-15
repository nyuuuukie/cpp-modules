/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:56:41 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/15 21:39:57 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"

Fixed::Fixed(void)
{
		
}

Fixed::~Fixed(void)
{
	
}

Fixed(const Fixed& other);

Fixed& operator=(const Fixed& other);

int getRawBits(void) const;

void setRawBits(int const raw);