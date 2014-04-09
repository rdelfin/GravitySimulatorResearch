#include "stdafx.h"

#pragma once

#include "Point.h"
#include "GameObject.h"

class GameState
{
public:
	GameState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState);

	Point getScreenSize();
	void stop();
	bool isRunning();

	virtual void Update(GameTime*) = 0;
	virtual void Draw() = 0;

	~GameState(void);

protected:
	ALLEGRO_KEYBOARD_STATE *keyState, *prevKeyState;

private:
	Point screenSize;
	bool running;
};

