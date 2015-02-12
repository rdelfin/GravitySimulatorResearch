#include "Sprite.h"
#include "GameTime.h"
#include "Point.h"
#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(std::string file, Point frameCount, int millPerFrame, Point initialPosition);

	virtual void Update(GameTime*, ALLEGRO_KEYBOARD_STATE*);
	virtual void Draw(Point camPos);

	~GameObject(void);

	Point position, velocity, acceleration;

protected:
	Sprite sprite;

};
