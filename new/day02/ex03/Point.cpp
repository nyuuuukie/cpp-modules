#include "Point.hpp"

Point::Point( void ) {
	this->_x = Fixed(0);
	this->_y = Fixed(0);
}

Point::~Point( void ) {

}

Point::Point( const Point &other ) {
	*this = other;
}

Point::Point( const float x, const float y ) {
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}
	
Point& Point::operator=( const Point &other ) {
	this->_x = Fixed(other._x);
	this->_y = Fixed(other._y);

	return *this;
}

const Fixed& Point::x( void ) const {
	return this->_x;
}

const Fixed& Point::y( void ) const {
	return this->_y;
}

void Point::x( const Fixed &p ) {
	this->_x = p;
}

void Point::y( const Fixed &p ) {
	this->_y = p;
}


Point operator+( const Point &lhs, const Point &rhs ) {
	Point res;

	res.x(lhs.x() + rhs.x());
	res.y(lhs.y() + rhs.y());
	return res;
}

Point operator-( const Point &lhs, const Point &rhs ) {
	Point res;

	res.x(lhs.x() - rhs.x());
	res.y(lhs.y() - rhs.y());
	return res;
}

Point operator*( const Point &lhs, const Point &rhs ) {
	Point res;

	res.x(lhs.x() * rhs.x());
	res.y(lhs.y() * rhs.y());
	return res;
}

Point operator/( const Point &lhs, const Point &rhs ) {
	Point res;

	res.x(lhs.x() / rhs.x());
	res.y(lhs.y() / rhs.y());
	return res;
}
