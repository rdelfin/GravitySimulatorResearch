#include "stdafx.h"

#include "Game.h"
#include "BaseGame.h"


Game::Game(void)
	: BaseGame(Vector2(1280, 800), true, "Gravity Simulator 1", 60)
{

}


void Game::Update(GameTime* gameTime)
{

}

void Game::Draw(GameTime* gameTime)
{
	al_draw_filled_rectangle(0, 0, 1280, 800, al_map_rgb(100, 149, 237));
	al_draw_filled_circle(400, 400, 50, al_map_rgb(255, 0, 0)); 
}

Game::~Game(void)
{
}

int main()
{
	BaseGame* game = new Game();
	game->run();
	delete game;

	return 0;
}