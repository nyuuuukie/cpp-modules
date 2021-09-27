#include "Point.hpp"

float substrVec( const Point a, const Point b, const Point p ) {
	Point d1 = b - a;
	Point d2 = p - a;

	return (d1.x() * d2.y() - d1.y() * d2.x()).toFloat();
}


bool bsp( Point const a, Point const b, Point const c, Point const p) {
	float s1 = substrVec(a, b, p);
	float s2 = substrVec(b, c, p);
	float s3 = substrVec(c, a, p);

	return ((s1 > 0.0f && s2 > 0.0f && s3 > 0.0f) 
		|| (s1 < 0.0f && s2 < 0.0f && s3 < 0.0f));
}
