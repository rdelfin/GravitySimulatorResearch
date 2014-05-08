#pragma once
class Vector2
{
public:
	Vector2(BigNum x, BigNum y);
	Vector2();

	Vector2 operator+(Vector2);
	Vector2 operator-(Vector2);

	Vector2 operator*(Vector2);
	Vector2 operator/(Vector2);

	Vector2 operator*(BigNum);
	Vector2 operator/(BigNum);

	BigNum length();
	BigNum angle();

	Vector2 normalize();

	~Vector2(void);
	
	BigNum x, y;
};

