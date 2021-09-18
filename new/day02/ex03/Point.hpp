#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
	
	public:
		Point( void );
		~Point( void );
		Point( const Point &other );
		Point( const float x, const float y );
	
		Point& operator=( const Point &other );

		const Fixed& x( void ) const;
		const Fixed& y( void ) const;
		void x( const Fixed &p );
		void y( const Fixed &p );

};

Point operator+( const Point &lhs, const Point &rhs );
Point operator-( const Point &lhs, const Point &rhs );
Point operator*( const Point &lhs, const Point &rhs );
Point operator/( const Point &lhs, const Point &rhs );
