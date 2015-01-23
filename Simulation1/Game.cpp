#include "stdafx.h"

#include "Game.h"
#include "BaseGame.h"
#include "ttmathbig.h"
#include "Point.h"
#include "PlanetTestState.h"

using namespace ttmath;


Game::Game(void)
	: BaseGame(Point(1280, 800), WINDOW, "Gravity Simulator 1", 30)
{
	currentState = new PlanetTestState(getWindowSize(), &keyState, &prevKeyState, &mouseState, &prevMouseState);
}


void Game::Update(GameTime* gameTime)
{
	currentState->Update(gameTime);
}

void Game::Draw(GameTime* gameTime)
{
	//al_map_rgb(100, 149, 237)
	al_draw_filled_rectangle(0, 0, 1280, 800, al_map_rgb(0, 0, 0));
	
	currentState->Draw();
}

Game::~Game(void)
{
	delete currentState;
}

int main()
{
	BaseGame* game = new Game();
	game->run();
	delete game;

	return 0;
}
