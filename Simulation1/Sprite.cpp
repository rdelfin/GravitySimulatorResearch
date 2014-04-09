#include "stdafx.h"
#include "Sprite.h"


Sprite::Sprite(void)
{
}

Sprite::Sprite(const char* file, Point frameCount, int millPerFrame, bool repeat)
{
	this->sprite = al_load_bitmap(file);
	this->imageSize = Point(al_get_bitmap_width(sprite), al_get_bitmap_height(sprite));
	this->frameCount = frameCount;
	this->frameSize = Point(imageSize.x / frameCount.x, imageSize.y / frameCount.y);
	this->currentFrame = Point(0, 0);
	this->millPerFrame = millPerFrame;
	this->timer = 0;
	this->flipped = false;
	this->repeat = repeat;
	this->finished = false;
}

Point Sprite::getImageSize() { return imageSize; }
Point Sprite::getFrameSize() { return frameSize; }
Point Sprite::getFrameCount() { return frameCount; }
Point Sprite::getCurrentFrame() { return currentFrame; }
bool Sprite::finishedAnim() { return finished; }

void Sprite::Update(GameTime* gameTime)
{
	timer += gameTime->getMillisecondsPerFrame();

	if(timer >= millPerFrame)
	{
		timer = 0;
		currentFrame.x++;
		if(currentFrame.x >= frameCount.x)
		{
			currentFrame.x = 0;
			currentFrame.y++;

			if(currentFrame.y >= frameCount.y)
			{
				if(repeat)
					currentFrame.y = 0;
				else
					finished = true;
			}
		}
	}
}


void Sprite::Draw(Point position)
{
	al_draw_bitmap_region(sprite, currentFrame.x * frameSize.x,
		currentFrame.y * frameSize.y, frameSize.x, frameSize.y, position.x,
		position.y, (flipped ? ALLEGRO_FLIP_HORIZONTAL : 0));
}

void Sprite::Draw(GameRectangle destinationRectangle)
{
	al_draw_scaled_bitmap(sprite, currentFrame.x * frameSize.x,
		currentFrame.y * frameSize.y, frameSize.x, frameSize.y, destinationRectangle.x,
		destinationRectangle.y, destinationRectangle.width, destinationRectangle.height,
		(flipped ? ALLEGRO_FLIP_HORIZONTAL : 0));
}

void Sprite::reset()
{
	currentFrame = Point(0, 0);
	timer = 0;
	finished = false;
}

void Sprite::flip(bool flipped) { this->flipped = flipped; }

void Sprite::setMillPerFrame(int millPerFrame) { this->millPerFrame = millPerFrame; }

Sprite::~Sprite(void)
{
}
