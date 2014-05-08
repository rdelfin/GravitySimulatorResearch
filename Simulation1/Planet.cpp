#include "stdafx.h"
#include "Planet.h"
#include "Util.h"
#include "BigGameRect.h"

Planet::Planet()
{
}

Planet::Planet(Vector2 position, Vector2 velocity, BigNum mass, BigNum radius, ALLEGRO_COLOR color)
{
	this->position = position;
	this->velocity = velocity;
	this->mass = mass;
	this->radius = radius;
	this->firstUpdate = true;
	this->color = color;
	this->ringDistance = 20;
}

void Planet::UpdateForce(vector<Planet*> planet)
{
	acceleration = Vector2();

	for(size_t i = 0; i < planet.size(); i++)
	{
		if(planet[i] == this)
			continue;

		Vector2 vectorDir = planet[i]->position - position;
		Big<2 ,5> distance = vectorDir.length();
		BigNum scalarAcceleration = Util::G * planet[i]->mass / (distance*distance);

		acceleration = acceleration + vectorDir.normalize() * scalarAcceleration;
	}
}

void Planet::UpdatePosition(BigNum timeStep)
{
	if(firstUpdate)
	{
		firstUpdate = false;

		velocity = velocity + acceleration * (timeStep / 2);
	}
	else
	{
		velocity = velocity + acceleration * timeStep;
	}

	position = position + velocity * timeStep;
}

void Planet::Draw(BigNum pixelToMeter, Vector2 camPos, Vector2 screenSize, int index, ALLEGRO_FONT* font)
{
	Vector2 camOrigin = Vector2(camPos.x - (screenSize.x * pixelToMeter / 2), camPos.y - (screenSize.y * pixelToMeter / 2));
	//BigGameRect drawRect(camPos.x - (screenSize.x * pixelToMeter / 2), camPos.y - (screenSize.y * pixelToMeter / 2), screenSize.x * pixelToMeter, screenSize.y * pixelToMeter);
	BigNum displaySize = radius / pixelToMeter;
	
	Vector2 pixelPosition = (position - camOrigin) / pixelToMeter;

	al_draw_filled_circle(pixelPosition.x.ToDouble(), pixelPosition.y.ToDouble(), displaySize.ToDouble(), color);

	al_draw_circle(pixelPosition.x.ToDouble(), pixelPosition.y.ToDouble(), displaySize.ToDouble() + ringDistance, color, 2);
	
	al_draw_textf(font, al_map_rgb(255, 255, 255), pixelPosition.x.ToDouble() - displaySize.ToDouble() - ringDistance - 10, pixelPosition.y.ToDouble() - displaySize.ToDouble() - ringDistance - 10, 0, "%i", index);

	/*if(displaySize < 5)
	{
		
	}*/
}


Vector2 Planet::getPosition() { return position; }


Planet::~Planet(void)
{

}
