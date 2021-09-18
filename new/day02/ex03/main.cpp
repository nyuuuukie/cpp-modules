#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p);

int main( void ) {
	
	for (int i = 0; i < 1; i++)
	{
		Point a(1.0f, 0.0f);
		Point b(3.0f, 3.0f);
		Point c(5.0f, 0.0f);
		Point p(3.0f, 1.5f);
		std::cout << "Inside:" << bsp(a, b, c, p) << std::endl;
	}
	return 0;
}
