#pragma once

#include <iostream>

class Fixed
{
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractionalCount;
};
