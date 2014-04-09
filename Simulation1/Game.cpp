#include "stdafx.h"

#include "Game.h"
#include "BaseGame.h"
#include "ttmathbig.h"
#include "Point.h"
#include "PlanetTestState.h"

using namespace ttmath;


Game::Game(void)
	: BaseGame(Point(1280, 800), FULLSCREEN_WINDOWED, "Gravity Simulator 1", 60)
{
	currentState = new PlanetTestState(getWindowSize(), &keyState, &prevKeyState);
	font = al_load_ttf_font("copyviol.ttf", 20, NULL);
}


void Game::Update(GameTime* gameTime)
{
	currentState->Update(gameTime);
}

void Game::Draw(GameTime* gameTime)
{
	//al_map_rgb(100, 149, 237)
	al_draw_filled_rectangle(0, 0, 1280, 800, al_map_rgb(0, 0, 0));
	al_draw_textf(font, al_map_rgb(255, 0, 0), 0, 0, NULL, "Frame Speed: %d", gameTime->getMillisecondsPerFrame());

	currentState->Draw();
}

Game::~Game(void)
{
	delete currentState;
	delete font;
}

int main()
{
	BaseGame* game = new Game();
	game->run();
	delete game;

	return 0;
}