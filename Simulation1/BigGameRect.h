#include "stdafx.h"
#include "Vector2.h"
#include "ttmathbig.h"

using namespace ttmath;

#pragma once
class BigGameRect
{
public:
	BigGameRect();
	BigGameRect(const BigNum& x, const BigNum& y, const BigNum& width, const BigNum& height);

	BigGameRect operator+(BigGameRect);
	BigGameRect operator+(Vector2);
	BigGameRect operator-(BigGameRect);
	BigGameRect operator-(Vector2);

	bool contains(Vector2);
	bool contains(BigGameRect);
	bool intersects(BigGameRect);

	~BigGameRect();

	BigNum x, y, width, height;

	BigNum bottom();
	BigNum top();
	BigNum right();
	BigNum left();

private:
	void init(const BigNum& x, const BigNum& y, const BigNum& width, const BigNum& height);
};
