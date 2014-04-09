#include "stdafx.h"
#include "Point.h"

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}


Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point Point::operator+(Point v)
{ return Point(x + v.x, y + v.y); }

Point Point::operator-(Point v)
{ return (*this) + Point(-v.x, -v.y); }

Point Point::operator+(double v)
{ return (*this) + Point(v, v); }

Point Point::operator-(double v)
{ return (*this) + (-v); }

Point Point::operator*(double d)
{ return Point(x * d, y * d); }
Point Point::operator/(double d)
{ return (*this) * (1/d); }


Point::~Point(void)
{
}
