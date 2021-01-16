/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:56:28 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/16 16:12:09 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		
		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		Fixed& operator=(const Fixed& other);
	
	private:
		int _value;
		static const int _fractionalCount;
};

std::ostream& operator<<(std::ostream &out, const Fixed& other);
