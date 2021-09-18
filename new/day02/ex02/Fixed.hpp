#pragma once

#include <iostream>
#include <string.h>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		~Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed &other );
		
		int getRawBits( void ) const;
		void setRawBits( int const raw );

		// Convertations
		int toInt( void ) const;
		float toFloat( void ) const;

		Fixed& operator=(const Fixed &other );

		// Comparison overloads
		bool operator>( const Fixed &rhs ) const;
		bool operator<( const Fixed &rhs ) const;
		bool operator>=( const Fixed &rhs ) const;
		bool operator<=( const Fixed &rhs ) const;
		bool operator!=( const Fixed &rhs ) const;
		bool operator==( const Fixed &rhs ) const;

		// Ariphmetic overloads
		Fixed operator+( const Fixed &rhs );
		Fixed operator-( const Fixed &rhs );
		Fixed operator*( const Fixed &rhs );
		Fixed operator/( const Fixed &rhs );

		//Increment and decrement overloading
		Fixed& operator--();
		Fixed& operator++();

		Fixed operator++(int);
		Fixed operator--(int);


		// Min & max functions
		static Fixed& min( Fixed &lhs, Fixed &rhs );
		static Fixed& max( Fixed &lhs, Fixed &rhs );
		static const Fixed& min( const Fixed &lhs, const Fixed &rhs );
		static const Fixed& max( const Fixed &lhs, const Fixed &rhs );

	private:
		int _value;
		static const int _fractionalCount;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);
