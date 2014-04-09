#pragma once
#include "GameState.h"
#include "Planet.h"
class SimulationState :
	public GameState
{
public:
	SimulationState(Point, ALLEGRO_KEYBOARD_STATE*, ALLEGRO_KEYBOARD_STATE* prevKeyState);
	~SimulationState(void);

private:
	vector<Planet*> planet;
};

