cc=g++
CXXFLAGS =-std=c++0x

all: Game

Game: BaseGame.o BigGameRect.o GameObject.o GameRectangle.o GameState.o GameTime.o MathHelper.o Planet.o PlanetTestState.o Point.o Sprite.o Util.o Utility.o Vector2.o
	g++ -std=c++0x -L/usr/lib/x86_64-linux-gnu/ Game.cpp BaseGame.o BigGameRect.o GameObject.o GameRectangle.o GameState.o GameTime.o MathHelper.o Planet.o PlanetTestState.o Point.o Sprite.o Util.o Utility.o Vector2.o -o Simulation `pkg-config --libs allegro-5.0 allegro_main-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_color-5.0 allegro_image-5.0 allegro_dialog-5.0 allegro_primitives-5.0 allegro_audio-5.0 allegro_acodec-5.0`

clean:
	rm -f *.o
	rm -f Simulation
