#include "Vector2.h"
#include "ttmathbig.h"

using namespace ttmath;

#pragma once
class BigGameRect
{
public:
	BigGameRect();
	BigGameRect(Big<2, 5> x, Big<2, 5> y, Big<2, 5> width, Big<2, 5> height);

	BigGameRect operator+(BigGameRect);
	BigGameRect operator+(Vector2);
	BigGameRect operator-(BigGameRect);
	BigGameRect operator-(Vector2);

	bool contains(Vector2);
	bool contains(BigGameRect);
	bool intersects(BigGameRect);

	~BigGameRect();
	
	Big<2, 5> x, y, width, height;

	Big<2, 5> bottom();
	Big<2, 5> top();
	Big<2, 5> right();
	Big<2, 5> left();
};

