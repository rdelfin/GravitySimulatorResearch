#include "stdafx.h"
#include "PlanetTestState.h"


PlanetTestState::PlanetTestState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState)
	: GameState(screenSize, keyState, prevKeyState)
{
	//TimeStep
	timeStep = Big<2, 5>(1);
	pixelToMeter = Big<2, 5>(1);

	//Planet initialization
	planets = vector<Planet*>();
	planets.push_back(new Planet(Vector2(0, -200), Vector2(-2, 0), 20, 20, al_map_rgb(255, 0, 0)));
	planets.push_back(new Planet(Vector2(0, 200), Vector2(2, 0), 20, 20, al_map_rgb(0, 255, 0)));
	//planets.push_back(new Planet(Vector2(-400, 0), Vector2(0, 0), 20, 20));
	//planets.push_back(new Planet(Vector2(0, 0), Vector2(0, 0), "5972190000000000000000000", "6371000", al_map_rgb(0, 0, 200)));
	//planets.push_back(new Planet(Vector2("10000000000", 0), Vector2(0, 0), "5972190000000000000000000", "6371000", al_map_rgb(255, 10, 10)));
}

void PlanetTestState::Update(GameTime*)
{
	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->UpdateForce(planets);

	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->UpdatePosition(timeStep);
}

void PlanetTestState::Draw()
{
	Vector2 screenSizeVec = Vector2(getScreenSize().x, getScreenSize().y);

	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->Draw(pixelToMeter, Vector2(0, 0), Vector2(getScreenSize().x, getScreenSize().y));
}


PlanetTestState::~PlanetTestState(void)
{
}
