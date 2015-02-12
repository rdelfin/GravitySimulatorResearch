#include "stdafx.h"
#include "GameObject.h"

using namespace std;

GameObject::GameObject()
{

}

GameObject::GameObject(string path, Point frameCount, int millPerFrame, Point initPos)
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

void GameObject::Draw(Point camPos)
{
	sprite.Draw(position - camPos);
}


GameObject::~GameObject(void)
{
}
