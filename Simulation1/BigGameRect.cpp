#include "stdafx.h"

#include "BigGameRect.h"


BigGameRect::BigGameRect()
{
	this->BigGameRect::BigGameRect(0, 0, 0, 0);
}

BigGameRect::BigGameRect(Big<2, 5> x, Big<2, 5> y, Big<2, 5> width, Big<2, 5> height)
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

Big<2, 5> BigGameRect::bottom() { return y + height; }
Big<2, 5> BigGameRect::top() { return y; }
Big<2, 5> BigGameRect::left() { return x; }
Big<2, 5> BigGameRect::right() { return x + width; }

BigGameRect::~BigGameRect(void)
{

}
