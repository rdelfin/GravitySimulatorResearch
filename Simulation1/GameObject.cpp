#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject()
{
	
}

GameObject::GameObject(string path, Vector2 frameCount, int millPerFrame, Vector2 initPos)
{
	sprite = Sprite(path.c_str(), frameCount, millPerFrame);
	position = initPos;
}

void GameObject::Update(GameTime* gameTime, ALLEGRO_KEYBOARD_STATE* keyState)
{
	sprite.Update(gameTime);

	velocity = velocity + acceleration * gameTime->getMillisecondsPerFrame();
	position = position + velocity * gameTime->getMillisecondsPerFrame();
}

void GameObject::Draw(Vector2 camPos)
{
	sprite.Draw(position - camPos);
}


GameObject::~GameObject(void)
{
}
