#include "iter.hpp"
#include <iostream>

class Awesome {

public:
	Awesome( void ) : _n( 42 ) {
		return;
	}
	int get( void ) const {
		return this->_n;
	}

private:
	int _n;
};

template< typename T >
void print( T const & x ) {
	std::cout << x << std::endl; 
	return;
}

template< typename T >
void print2( T & x ) {
	std::cout << x << std::endl; 
	return;
}

int main() {
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab, 5, print2 );
	iter( tab2, 5, print2 );
	return 0;
}
