#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p);

int main( void ) {

	// https://www.desmos.com/calculator
	
	Point a(0.0f, 2.25f);
	Point b(-4.5f, -2.25f);
	Point c(1.5f, 0.75f);
	Point p(-1.0f, -1.0f);
	
	std::cout << "Inside:" << bsp(a, b, c, p) << std::endl;
	
	return 0;
}
