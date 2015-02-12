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
	std::chrono::time_point<std::chrono::system_clock> start, lastFrame, currFrame;

};
