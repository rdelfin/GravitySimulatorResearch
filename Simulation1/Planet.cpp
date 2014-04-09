#include "stdafx.h"
#include "Planet.h"
#include "Util.h"
#include "BigGameRect.h"

Planet::Planet()
{
}

Planet::Planet(Vector2 position, Vector2 velocity, Big<2, 5> mass, Big<2, 5> radius, ALLEGRO_COLOR color)
{
	this->position = position;
	this->velocity = velocity;
	this->mass = mass;
	this->radius = radius;
	this->firstUpdate = true;
	this->color = color;
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
		Big<2, 5> scalarAcceleration = Util::G * planet[i]->mass / (distance*distance);

		acceleration = vectorDir * scalarAcceleration;
	}
}

void Planet::UpdatePosition(Big<2, 5> timeStep)
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

void Planet::Draw(Big<2, 5> pixelToMeter, Vector2 camPos, Vector2 screenSize)
{
	Vector2 camOrigin = Vector2(camPos.x - (screenSize.x * pixelToMeter / 2), camPos.y - (screenSize.y * pixelToMeter / 2));
	//BigGameRect drawRect(camPos.x - (screenSize.x * pixelToMeter / 2), camPos.y - (screenSize.y * pixelToMeter / 2), screenSize.x * pixelToMeter, screenSize.y * pixelToMeter);
	Big<2, 5> displaySize = radius / pixelToMeter;
	
	Vector2 pixelPosition = (position - camOrigin) / pixelToMeter;

	al_draw_filled_circle(pixelPosition.x.ToDouble(), pixelPosition.y.ToDouble(), displaySize.ToDouble(), color);

	al_draw_circle(pixelPosition.x.ToDouble(), pixelPosition.y.ToDouble(), displaySize.ToDouble() + 20, color, 2);

	/*if(displaySize < 5)
	{
		
	}*/
}


Planet::~Planet(void)
{

}
