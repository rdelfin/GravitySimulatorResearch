#pragma once
#include "GameState.h"
#include "Planet.h"

class PlanetTestState :
	public GameState
{
public:
	PlanetTestState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState);

	virtual void Update(GameTime*);
	virtual void Draw();

	std::vector<Planet*> planets;

	~PlanetTestState(void);

private:
	BigNum timeStep;
	Vector2 camCenter;
	BigNum pixelToMeter;
	BigNum baseZoom;
	BigNum baseSpeed;
	ALLEGRO_FONT* font;
	//-1 if camera is free. Otherwise, it indicates the index of the body in the camera's center
	int camFocus;
};
