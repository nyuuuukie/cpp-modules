/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 19:56:28 by mhufflep          #+#    #+#             */
/*   Updated: 2021/01/15 21:39:18 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed
{
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _value;
		static const int _fractionalCount = 8;
};
