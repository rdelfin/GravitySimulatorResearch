#include "stdafx.h"
#include "SimulationState.h"


SimulationState::SimulationState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState)
	: GameState(screenSize, keyState, prevKeyState)
{
	planet = vector<Planet*>();
	//planet.push_back(new Planet(
}


SimulationState::~SimulationState(void)
{
}
