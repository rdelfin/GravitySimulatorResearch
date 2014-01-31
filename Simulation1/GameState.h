#include "stdafx.h"

#pragma once

#include "Vector2.h"
#include "GameObject.h"

class GameState
{
public:
	GameState(Vector2 screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState);

	Vector2 getScreenSize();
	void stop();
	bool isRunning();

	virtual void Update(GameTime*) = 0;
	virtual void Draw() = 0;

	~GameState(void);

protected:
	ALLEGRO_KEYBOARD_STATE *keyState, *prevKeyState;

private:
	Vector2 screenSize;
	bool running;
};

