#include "stdafx.h"
#include "PlanetTestState.h"


PlanetTestState::PlanetTestState(Point screenSize, ALLEGRO_KEYBOARD_STATE* keyState, ALLEGRO_KEYBOARD_STATE* prevKeyState, ALLEGRO_MOUSE_STATE* mouseState, ALLEGRO_MOUSE_STATE* prevMouseState)
	: GameState(screenSize, keyState, prevKeyState, mouseState, prevMouseState)
{
	//TimeStep
	timeStep = 100000;
	pixelToMeter = 500000000;
	baseZoom = 500000000;
	baseSpeed = 100000;
	camCenter = Vector2(0, 0);
	font = al_load_ttf_font("harabara.ttf", 18, 0);
	camFocus = -1;

	//Planet initialization
	//Sun
	planets.push_back(new Planet(Vector2(0, 0), Vector2(0, 0), "1988550000000000000000000000000", "696342000", al_map_rgb(255, 255, 0)));
	//Mercury
	planets.push_back(new Planet(Vector2(0, 57909100000), Vector2(47870, 0), "330220000000000000000000", "2439700", al_map_rgb(150, 150, 150)));
	//Venus
	planets.push_back(new Planet(Vector2(108208000000, 0), Vector2(0, -35020), "4867600000000000000000000", "6051800", al_map_rgb(204, 153, 0)));
	//Earth
	planets.push_back(new Planet(Vector2(-149600000000, 0), Vector2(0, 29780), "5972190000000000000000000", "6371000", al_map_rgb(0, 0, 255)));
	//Mars
	planets.push_back(new Planet(Vector2(0, -227939100000), Vector2(24077, 0), "641850000000000000000000", "3389500", al_map_rgb(153, 92, 0)));
	//Jupiter
	planets.push_back(new Planet(Vector2(778547200000, 0), Vector2(0, 13070), "1898600000000000000000000000", "69911000", al_map_rgb(184, 148, 77)));
	//Saturn
	planets.push_back(new Planet(Vector2(-1433449370000, 0), Vector2(0, 9690), "568460000000000000000000000", "58232000", al_map_rgb(255, 194, 102)));
}

void PlanetTestState::Update(GameTime*)
{
	/*Updates for planets. It first has to calculate the forces individually and then move the objects. Otherwise, the order of the
	 * List will affect the result.*/
	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->UpdateForce(planets);

	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->UpdatePosition(timeStep);


	//Pause
	if(al_key_down(keyState, ALLEGRO_KEY_P) && !al_key_down(prevKeyState, ALLEGRO_KEY_P))
		timeStep = (timeStep == 0 ? baseSpeed : 0);

	//Camera movement. It firsts gets the boolean for each movement and then uses a series of if's to move the camera
	bool left = al_key_down(keyState, ALLEGRO_KEY_LEFT) || al_key_down(keyState, ALLEGRO_KEY_A);
	bool right = al_key_down(keyState, ALLEGRO_KEY_RIGHT) || al_key_down(keyState, ALLEGRO_KEY_D);
	bool up = al_key_down(keyState, ALLEGRO_KEY_UP) || al_key_down(keyState, ALLEGRO_KEY_W);
	bool down = al_key_down(keyState, ALLEGRO_KEY_DOWN) || al_key_down(keyState, ALLEGRO_KEY_S);
	BigNum moveSpeed = 5;

	//If the camera is in free movement
	if(camFocus == -1)
	{
		if(left != right)
		{
			if(left)
				camCenter.x -= moveSpeed * pixelToMeter;
			else if(right)
				camCenter.x += moveSpeed * pixelToMeter;
		}

		if(up != down)
		{
			if(down)
				camCenter.y += moveSpeed * pixelToMeter;
			else if(up)
				camCenter.y -= moveSpeed * pixelToMeter;
		}
	}
	//If the camera is centered around a planet
	else
	{
		if(camFocus >= 0 && camFocus < planets.size())
		{
			Vector2 planetPos = planets[camFocus]->getPosition();
			camCenter = planetPos;
		}

		if(up || down || left || right)
			camFocus = -1;
	}

	//---------------------------------------- Switch body focus -----------------------------------------------------
	//Move up
	if(al_key_down(keyState, ALLEGRO_KEY_E) && !al_key_down(prevKeyState, ALLEGRO_KEY_E) && camFocus < (int)planets.size() - 1)
		camFocus++;

	//Move down
	if(al_key_down(keyState, ALLEGRO_KEY_Q) && !al_key_down(prevKeyState, ALLEGRO_KEY_Q) && camFocus > -1)
		camFocus--;

	//Reset
	if(al_key_down(keyState, ALLEGRO_KEY_R) && !al_key_down(prevKeyState, ALLEGRO_KEY_R))
		camFocus = -1;

	//Camera zoom. Uses the mouse's scroll wheel.

	//                                                  v--- Scrollwheel index on the y axis
	int scrollPos = al_get_mouse_state_axis(mouseState, 2);
	int prevScrollPos = al_get_mouse_state_axis(prevMouseState, 2);

	if(prevScrollPos != scrollPos)
	{
		pixelToMeter += (BigNum(prevScrollPos) - BigNum(scrollPos)) * pixelToMeter * BigNum(0.05);
	}
}

void PlanetTestState::Draw()
{
	Vector2 screenSizeVec = Vector2(getScreenSize().x, getScreenSize().y);

	for(size_t i = 0; i < planets.size(); i++)
		planets[i]->Draw(pixelToMeter, camCenter, Vector2(getScreenSize().x, getScreenSize().y), i, font);

	char temp[20];
	sprintf(temp, "Focus: %s", (camFocus < 0 ? "None" : "%i"));

	if(camFocus < 0)
		al_draw_text(font, al_map_rgb(255, 255, 255), 0, 20, 0, temp);
	else
		al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 20, 0, temp, camFocus);
}


PlanetTestState::~PlanetTestState(void)
{
	delete font;
}
