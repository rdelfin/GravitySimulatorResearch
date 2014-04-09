#include "stdafx.h"
#include "GameState.h"

GameState::GameState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState)
{
	this->screenSize = screenSize;
	running = true;
	this->keyState = keyState;
	this->prevKeyState = prevKeyState;
}

Point GameState::getScreenSize() { return screenSize; }

void GameState::stop() { running = false; }
bool GameState::isRunning() { return running; }

GameState::~GameState(void)
{
}
