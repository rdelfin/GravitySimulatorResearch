#include "stdafx.h"

#include "BigGameRect.h"


BigGameRect::BigGameRect()
{
	init(0, 0, 0, 0);
}

BigGameRect::BigGameRect(const BigNum& x, const BigNum& y, const BigNum& width, const BigNum& height)
{
	init(x, y, width, height);
}

void BigGameRect::init(const BigNum& x, const BigNum& y, const BigNum& width, const BigNum& height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

BigGameRect BigGameRect::operator+(BigGameRect r)
{ return BigGameRect(x + r.x, y + r.y, width + r.width, height + r.height); }
BigGameRect BigGameRect::operator+(Vector2 v)
{ return BigGameRect(x + v.x.ToDouble(), y + v.y.ToDouble(), width, height); }
BigGameRect BigGameRect::operator-(BigGameRect r)
{ return *this + BigGameRect(-r.x, -r.y, -r.width, -r.height); }
BigGameRect BigGameRect::operator-(Vector2 v)
{ return *this + Vector2(-v.x, -v.y); }

bool BigGameRect::contains(Vector2 v)
{
	bool horizontalInside = v.x > x && v.x < x + width;
	bool verticalInside = v.y > y && v.y < y + height;
	return horizontalInside && verticalInside;
}

bool BigGameRect::contains(BigGameRect r)
{
	bool horizontalContains = r.x >= x && r.x + r.width <= x + width;
	bool verticalContains = r.y >= y && r.y + r.height <= y + height;

	return horizontalContains && verticalContains;
}

bool BigGameRect::intersects(BigGameRect r)
{
	bool horizontalInside = x + width > r.x && x < r.x + r.width;
	bool verticalInside = y + height > r.y && y < r.y + r.height;

	return horizontalInside && verticalInside;
}

BigNum BigGameRect::bottom() { return y + height; }
BigNum BigGameRect::top() { return y; }
BigNum BigGameRect::left() { return x; }
BigNum BigGameRect::right() { return x + width; }

BigGameRect::~BigGameRect(void)
{

}
