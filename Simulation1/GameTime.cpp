#include "stdafx.h"
#include "GameTime.h"

GameTime::GameTime(void)
{
	start = milliseconds_now();
	lastFrame = start;
	currFrame = start;
}


GameTime::~GameTime(void)
{
	
}

long long GameTime::getElapsedGameTime() { return start - currFrame; }
long long GameTime::getMillisecondsPerFrame() { return currFrame - lastFrame; }


void GameTime::Update()
{
	lastFrame = currFrame;
	currFrame = milliseconds_now();
}

long long GameTime::milliseconds_now()
{
    static LARGE_INTEGER s_frequency;
    static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc)
	{
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    }
	else
	{
        return GetTickCount64();
    }
}

void GameTime::reset()
{
	start = milliseconds_now();
	lastFrame = start;
	currFrame = start;
}