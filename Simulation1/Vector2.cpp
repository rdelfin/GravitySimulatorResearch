#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2(BigNum x, BigNum y)
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
{ return (*this) * Vector2(BigNum(1)/v.x, BigNum(1)/v.y); }

Vector2 Vector2::operator*(BigNum d)
{ return (*this) * Vector2(d, d); }

Vector2 Vector2::operator/(BigNum d)
{ return (*this) * Vector2(BigNum(1)/d, BigNum(1)/d); }




BigNum Vector2::length()
{
	return Sqrt(x*x + y*y);
}

BigNum Vector2::angle()
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
