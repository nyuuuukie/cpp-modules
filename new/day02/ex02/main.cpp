#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	
	Fixed a;
	Fixed b;

	std::cout << "Addition" << std::endl;
	a = Fixed(5.25f) + Fixed(7);
	std::cout << "5.25f + 7 = " << a << std::endl;
	a = Fixed(5.25f) + Fixed(-7);
	std::cout << "5.25f + (-7) = " << a << std::endl;
	a = Fixed(2147483647.25f) + Fixed(7);
	std::cout << "2147483647.25f + 7 = " << a << std::endl;
	
	std::cout << std::endl << "Subtraction" << std::endl;
	a = Fixed(5.25f) - Fixed(7);
	std::cout << "5.25f - 7 = " << a << std::endl;
	a = Fixed(5.25f) - Fixed(-7);
	std::cout << "5.25f - (-7) = " << a << std::endl;
	a = Fixed(-1000000.25f) - Fixed(-7);
	std::cout << "-1000000.25 - (-7) = " << a << std::endl;
	
	std::cout << std::endl << "Multiplication" << std::endl;
	a = Fixed(5.125f) * Fixed(2);
	std::cout << "5.125f * 2 = " << a << std::endl;
	a = Fixed(5.125f) * Fixed(-2);
	std::cout << "5.125f * (-2) = " << a << std::endl;
	a = Fixed(5.125f) * Fixed(0);
	std::cout << "5.125f * 0 = " << a << std::endl;

	std::cout << std::endl << "Division" << std::endl;
	a = Fixed(5.05f) / Fixed(2);
	std::cout << "5.05f / 2 = " << a << std::endl;
	a = Fixed(5.05f) / Fixed(-2);
	std::cout << "5.05f / -2 = " << a << std::endl;
	a = Fixed(5.05f) / Fixed(0);
	std::cout << "5.05f / 0 = " << a << std::endl;
	
	std::cout << std::endl << "Increment" << std::endl;
	a = 0;
	std::cout << "a=" << a << std::endl;
	std::cout << "Post (a++): " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "Pre (++a): " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "(++a)++ = " << (++a)++ << std::endl;
	std::cout << "a = " << a << std::endl;
	
	std::cout << std::endl << "Decrement" << std::endl;
	std::cout << "a=" << a << std::endl;
	std::cout << "Post (a--): " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "Pre (--a): " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "(--a)-- = " << (--a)-- << std::endl;
	std::cout << "a = " << a << std::endl;
	
	std::cout << std::endl << "Min & Max" << std::endl;
	a = 21.35f;
	std::cout << "min(1243.25f, 21.35f) = " << Fixed::min( Fixed(1243.25f), a ) << std::endl;
	std::cout << "max(1243.25f, 21.35f) = " << Fixed::max( Fixed(1243.25f), a ) << std::endl;
	
	return 0;
}
