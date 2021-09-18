#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	_value = roundf(num * (1 << _fractionalCount));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
	_value = num << _fractionalCount;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = other.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream &out, const Fixed& other)
{
	return out << other.toFloat();
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{	
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _fractionalCount));
}

int Fixed::toInt(void) const
{
	return (int)this->toFloat();
}

const int Fixed::_fractionalCount = 8;
