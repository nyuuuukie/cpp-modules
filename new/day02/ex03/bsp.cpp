#include "Point.hpp"

//float sign(const Point p1, const Point p2, const Point p3)
//{
//    return ((p1.x() - p3.x()) * (p2.y() - p3.y()) - (p2.x() - p3.x()) * (p1.y() - p3.y())).toFloat();
//}

//bool PointInTriangle(const Point pt, const Point v1, const Point v2, const Point v3)
//{
//    float d1, d2, d3;
//    bool has_neg, has_pos;

//    d1 = sign(pt, v1, v2);
//    d2 = sign(pt, v2, v3);
//    d3 = sign(pt, v3, v1);

//    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

//    return !(has_neg && has_pos);
//}

//float matrixDet(const Fixed a00, const Fixed a01, const Fixed a10, const Fixed a11)
//{
//	return ((a00 * a11) - (a01 * a01)).toFloat();
//}

//position = sign((Bx - Ax) * (Y - Ay) - (By - Ay) * (X - Ax))
//It is 0 on the line, and +1 on one side, -1 on the other side.
float substrVec( const Point a, const Point b, const Point p ) {
	Point d1 = b - a;
	Point d2 = p - a;

	return (d1.x() * d2.y() - d1.y() * d2.x()).toFloat();
}


bool bsp( Point const a, Point const b, Point const c, Point const p) {
	//Point v0 = b - a; 
	//Point v1 = c - a;
	//Point v2 = p - a;

    //float den = matrixDet(v0.x(), v0.y(), v1.x(), v1.y());
    //float v = matrixDet(v2.x(), v2.y(), v1.x(), v1.y()) / den;
    //float w = matrixDet(v0.x(), v0.y(), v2.x(), v2.y()) / den;
    //float u = 1.0f - v - w;

	float s1 = substrVec(a, b, p);
	float s2 = substrVec(b, c, p);
	float s3 = substrVec(c, a, p);

	return ((s1 > 0.0f && s2 > 0.0f && s3 > 0.0f)
		 || (s1 < 0.0f && s2 < 0.0f && s3 < 0.0f));
}
