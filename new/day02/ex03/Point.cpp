#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::~Point( void ) {}

Point::Point( const Point &other ) {
	*this = other;
}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}
	
Point& Point::operator=( const Point &other ) {
	if (this != &other) {
		const_cast<Fixed &>(this->_x) = other.x();
		const_cast<Fixed &>(this->_y) = other.y();
	}
	return *this;
}

const Fixed& Point::x( void ) const {
	return this->_x;
}

const Fixed& Point::y( void ) const {
	return this->_y;
}

void Point::x( const Fixed &p ) {
	Point res = Point(p.toFloat(), this->_y.toFloat());
	
	*this = res;
}

void Point::y( const Fixed &p ) {
	Point res = Point(this->_x.toFloat(), p.toFloat());
	
	*this = res;
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
