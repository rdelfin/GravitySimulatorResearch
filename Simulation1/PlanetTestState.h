#pragma once
#include "GameState.h"
#include "Planet.h"

class PlanetTestState :
	public GameState
{
public:
	PlanetTestState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState);

	virtual void Update(GameTime*);
	virtual void Draw();

	vector<Planet*> planets;

	~PlanetTestState(void);

private:
	Big<2, 5> timeStep;
	Big<2, 5> pixelToMeter;
};

