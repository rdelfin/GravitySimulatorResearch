#include "stdafx.h"

#pragma once

#include "Point.h"
#include "GameObject.h"

class GameState
{
public:
	GameState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);

	Point getScreenSize();
	void stop();
	bool isRunning();

	virtual void Update(GameTime*) = 0;
	virtual void Draw() = 0;

	~GameState(void);

protected:
	ALLEGRO_KEYBOARD_STATE *keyState, *prevKeyState;
	ALLEGRO_MOUSE_STATE *mouseState, *prevMouseState;

private:
	Point screenSize;
	bool running;
};

