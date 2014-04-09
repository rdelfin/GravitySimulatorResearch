#pragma once
class Vector2
{
public:
	Vector2(Big<2, 10> x, Big<2, 10> y);
	Vector2();

	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);

	Vector2 operator*(Vector2);
	Vector2 operator/(Vector2);

	Vector2 operator*(Big<2, 10>);
	Vector2 operator/(Big<2, 10>);

	Big<2, 10> length();
	Big<2, 10> angle();

	Vector2 normalize();

	~Vector2(void);
	
	Big<2, 10> x, y;
};

