#include "stdafx.h"

#include "BaseGame.h"

using namespace ttmath;
using namespace std;

const ALLEGRO_COLOR BaseGame::CORNFLOWER_BLUE = al_map_rgb(100, 149, 237);
const ALLEGRO_COLOR BaseGame::WHITE = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR BaseGame::BLACK = al_map_rgb(0, 0, 0);

BaseGame::BaseGame(Point windowSize, ScreenType screenType, string screenTitle, double fps) : fps(fps)
{
	this->windowSize = windowSize;
	initScreen(screenType, screenTitle);
	initModules();

	al_get_keyboard_state(&keyState);
	al_get_mouse_state(&mouseState);

	eventQueue = al_create_event_queue();
	timer = al_create_timer(1/this->fps);

	//Events to read
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	al_register_event_source(eventQueue, al_get_timer_event_source(timer));
	al_register_event_source(eventQueue, al_get_display_event_source(display));
	al_register_event_source(eventQueue, al_get_mouse_event_source());

	running = true;
}

void BaseGame::initScreen(ScreenType screenType, string screenTitle)
{
	if(!al_init())
	{
		cout << "Could not initialize Allegro 5" << endl;
		//al_show_native_message_box(NULL, "Error", "Error", "Could not initialize Allegro 5", NULL, 0);
		exit(-1);
	}

	int displayFlags = 0;
	switch(screenType)
	{
		case WINDOW: displayFlags = ALLEGRO_WINDOWED; break;
		case FULLSCREEN: displayFlags = ALLEGRO_FULLSCREEN; break;
		case FULLSCREEN_WINDOWED: displayFlags = ALLEGRO_FULLSCREEN | ALLEGRO_FULLSCREEN_WINDOW; break;
		default: displayFlags = ALLEGRO_WINDOWED;
	}
	al_set_new_display_flags(displayFlags);

	display = al_create_display(windowSize.x, windowSize.y);

	if(!display)
	{
		cout << "Could not create Allegro Window" << endl;
		//al_show_native_message_box(display, "Error", "Error", "Could not create Allegro Window", NULL, 0);
		exit(-1);
	}

	al_set_window_position(display, 0, 0);
	al_set_window_title(display, screenTitle.c_str());
}

void BaseGame::initModules()
{
	al_init_font_addon();
	if(!(al_init_ttf_addon() &&
		al_init_primitives_addon() &&
		al_init_image_addon() &&
		al_init_acodec_addon() &&
		al_install_keyboard() &&
		al_install_mouse() &&
		al_install_audio() &&
		al_install_joystick()))
	{
		cout << "Error while loading allegro modules. Please contact distributor and inform them of this error." << endl;
		//al_show_native_message_box(display, "Error!", "ERROR 42 (0x2a)",
			//"Error while loading allegro modules. Please contact distributor and inform them of this error.", NULL, 0);
		exit(42);
	}
}

void BaseGame::stop() { running = false; }

void BaseGame::run()
{
	gameTime = new GameTime();

	al_start_timer(timer);
	while(running)
	{
		ALLEGRO_EVENT events;
		al_wait_for_event(eventQueue, &events);

		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}
		else if(events.type == ALLEGRO_EVENT_TIMER)
		{
			gameTime->Update();

			prevMouseState = mouseState;
			prevKeyState = keyState;

			al_get_keyboard_state(&keyState);
			al_get_mouse_state(&mouseState);

			Update(gameTime);
			Draw(gameTime);

			al_flip_display();
			al_clear_to_color(CORNFLOWER_BLUE);
		}
	}
}

Point BaseGame::getWindowSize() { return windowSize; }

BaseGame::~BaseGame(void)
{
	delete gameTime;
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(eventQueue);
}
