#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_value = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(float num)
{
	_value = roundf(num * (1 << _fractionalCount));
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int num)
{
	_value = num << _fractionalCount;
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->_value = other.getRawBits();
	return *this;
}


int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{	
	this->_value = raw;
}

// Convertations functions
float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / static_cast<float>(1 << _fractionalCount));
}

int Fixed::toInt(void) const
{
	return static_cast<int>(this->toFloat());
}

// Comparison operator overloading
bool Fixed::operator>( const Fixed &rhs ) const {
	return this->_value > rhs._value;
}

bool Fixed::operator<( const Fixed &rhs ) const {
	return this->_value < rhs._value;
}

bool Fixed::operator>=( const Fixed &rhs ) const {
	return this->_value >= rhs._value;
}

bool Fixed::operator<=( const Fixed &rhs ) const {
	return this->_value <= rhs._value;
}

bool Fixed::operator!=( const Fixed &rhs ) const {
	return this->_value != rhs._value;
}

bool Fixed::operator==( const Fixed &rhs ) const {
	return this->_value == rhs._value;
}

// Ariphmetic overloads
Fixed Fixed::operator+( const Fixed &rhs ) const {
	Fixed res;

	res._value = this->_value + rhs._value;
	return res;
}

Fixed Fixed::operator-( const Fixed &rhs ) const {
	Fixed res;

	res._value = this->_value - rhs._value;
	return res;
}

Fixed Fixed::operator*( const Fixed &rhs ) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/( const Fixed &rhs ) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++() {
   this->_value++;
   return *this;
}

Fixed Fixed::operator++(int) {
   Fixed temp = *this;
   
   this->_value++;
   return temp;
}

Fixed& Fixed::operator--() {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
   Fixed temp = *this;
   
   this->_value--;
   return temp;
}

// Min & max
Fixed& Fixed::min( Fixed &lhs, Fixed &rhs ) {
	return lhs < rhs ? lhs : rhs;
}

Fixed& Fixed::max( Fixed &lhs, Fixed &rhs ) {
	return lhs > rhs ? lhs : rhs;
}

const Fixed& Fixed::min( const Fixed &lhs, const Fixed &rhs ) {
	return lhs < rhs ? lhs : rhs;
}

const Fixed& Fixed::max( const Fixed &lhs, const Fixed &rhs ) {
	return lhs > rhs ? lhs : rhs;
}

// Outstream operator overloading
std::ostream& operator<<(std::ostream &out, const Fixed& other) {
	return out << other.toFloat();
}

const int Fixed::_fractionalCount = 8;
