#include "stdafx.h"

#include "Point.h"
#include "GameTime.h"

#pragma once

enum ScreenType
{
	FULLSCREEN,
	FULLSCREEN_WINDOWED,
	WINDOW
};

class BaseGame
{
public:
	//Colors
	static const ALLEGRO_COLOR CORNFLOWER_BLUE;
	static const ALLEGRO_COLOR WHITE;
	static const ALLEGRO_COLOR BLACK;

	//Constructors
	BaseGame(Point windowSize, ScreenType screenType, std::string windowTitle, double fps);

	//Getters and Setters
	Point getWindowSize();
	void stop();

	//Update and Draw
	virtual void Update(GameTime*) = 0;
	virtual void Draw(GameTime*) = 0;

	//Run
	void run();

	~BaseGame();


protected:
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_KEYBOARD_STATE prevKeyState;
	ALLEGRO_MOUSE_STATE mouseState;
	ALLEGRO_MOUSE_STATE prevMouseState;

private:
	void initScreen(ScreenType, std::string);
	void initModules();

	Point windowSize;
	GameTime* gameTime;
	bool running;

	const double fps;

	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE* eventQueue;
};
