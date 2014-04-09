#include "stdafx.h"
#include "Vector2.h"
#pragma once
class Planet
{
public:
	Planet();
	Planet(Vector2 position, Vector2 velocity, Big<2, 5> mass, Big<2, 5> radius, ALLEGRO_COLOR color);
	
	void UpdateForce(vector<Planet*>);
	void UpdatePosition(Big<2, 5> timeStep);

	void Draw(Big<2, 5> pixelToMeter, Vector2 camPos, Vector2 screenSize);

	~Planet(void);

private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	Big<2, 5> mass;
	Big<2, 5> radius;

	ALLEGRO_COLOR color;

	long timeStep;

	bool firstUpdate;

};

