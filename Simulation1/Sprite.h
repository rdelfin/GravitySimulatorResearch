#include "stdafx.h"
#include "Point.h"
#include "GameTime.h"
#include "GameRectangle.h"

#pragma once
class Sprite
{
public:
	Sprite(void);
	Sprite(const char* file, Point frameCount, int millPerFrame = 200, bool repeat = true);

	void Update(GameTime*);
	void Draw(Point);
	void Draw(GameRectangle destinationRectangle);
	
	void flip(bool = true);

	void setMillPerFrame(int);

	void reset();

	bool finishedAnim();

	Point getFrameSize();
	Point getImageSize();
	Point getFrameCount();
	Point getCurrentFrame();

	~Sprite(void);

private:
	ALLEGRO_BITMAP* sprite;
	Point imageSize, frameSize, frameCount, currentFrame;
	int millPerFrame, timer;
	bool flipped, repeat, finished;
};

