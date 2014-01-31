#include "stdafx.h"
#pragma once
class GameTime
{
public:
	GameTime();
	~GameTime();

	void Update();
	long long getMillisecondsPerFrame();
	long long getElapsedGameTime();

	static long long milliseconds_now();

	void reset();

private:
	long long start;
	long long lastFrame;
	long long currFrame;

};

