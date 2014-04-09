#pragma once
class Point
{
public:
	Point(double x, double y);
	Point();

	Point operator+(Point);
	Point operator-(Point);

	Point operator+(double);
	Point operator-(double);

	Point operator*(double);
	Point operator/(double);

	~Point(void);
	
	double x, y;
};

