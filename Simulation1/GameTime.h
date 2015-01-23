#include "stdafx.h"

#pragma once
class GameTime
{
public:
	GameTime();
	~GameTime();

	void Update();
	double getMillisecondsPerFrame();
	double getElapsedGameTime();

	void reset();

private:
	time_point<system_clock> start, lastFrame, currFrame;

};
