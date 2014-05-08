#include "stdafx.h"
#include "Vector2.h"
#pragma once
class Planet
{
public:
	Planet();
	Planet(Vector2 position, Vector2 velocity, BigNum mass, BigNum radius, ALLEGRO_COLOR color);
	
	void UpdateForce(vector<Planet*>);
	void UpdatePosition(BigNum timeStep);

	void Draw(BigNum pixelToMeter, Vector2 camPos, Vector2 screenSize, int index, ALLEGRO_FONT*);

	Vector2 getPosition();

	~Planet(void);

private:
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;

	BigNum mass;
	BigNum radius;

	ALLEGRO_COLOR color;

	long timeStep;

	double ringDistance;

	bool firstUpdate;

};

