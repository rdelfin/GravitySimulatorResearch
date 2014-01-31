#include "Sprite.h"
#include "GameTime.h"
#pragma once
class GameObject
{
public:
	GameObject();
	GameObject(string file, Vector2 frameCount, int millPerFrame, Vector2 initialPosition);

	virtual void Update(GameTime*, ALLEGRO_KEYBOARD_STATE*);
	virtual void Draw(Vector2 camPos);

	~GameObject(void);
	
	Vector2 position, velocity, acceleration;

protected:
	Sprite sprite;

};

