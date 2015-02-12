#include "stdafx.h"
#include "GameTime.h"

using namespace std::chrono;

GameTime::GameTime(void)
{
	start = system_clock::now();
	lastFrame = start;
	currFrame = start;
}


GameTime::~GameTime(void)
{

}

double GameTime::getElapsedGameTime()
{

	return (start - currFrame).count() * 1000;
}

double GameTime::getMillisecondsPerFrame() { return (currFrame - lastFrame).count() * 1000; }


void GameTime::Update()
{
	lastFrame = currFrame;
	currFrame = system_clock::now();
}

void GameTime::reset()
{
	start = system_clock::now();
	lastFrame = start;
	currFrame = start;
}
