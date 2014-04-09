#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2(Big<2, 10> x, Big<2, 10> y)
{
	this->x = x;
	this->y = y;
}


Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2 Vector2::operator+(Vector2 v)
{ return Vector2(x + v.x, y + v.y); }

Vector2 Vector2::operator-(Vector2 v)
{ return (*this) + Vector2(-v.x, -v.y); }

Vector2 Vector2::operator*(Vector2 v)
{ return Vector2(x * v.x, y * v.y); }

Vector2 Vector2::operator/(Vector2 v)
{ return (*this) * Vector2(Big<2, 10>(1)/v.x, Big<2, 10>(1)/v.y); }

Vector2 Vector2::operator*(Big<2, 10> d)
{ return (*this) * Vector2(d, d); }

Vector2 Vector2::operator/(Big<2, 10> d)
{ return (*this) * Vector2(Big<2, 10>(1)/d, Big<2, 10>(1)/d); }




Big<2, 10> Vector2::length()
{
	return Sqrt(x*x + y*y);
}

Big<2, 10> Vector2::angle()
{
	return ACos(x / length());
}

Vector2 Vector2::normalize()
{
	return Vector2(x / length(), y / length());
}

Vector2::~Vector2()
{
}
