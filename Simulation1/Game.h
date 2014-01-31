#pragma once

#include "BaseGame.h"
#include "GameTime.h"

class Game : public BaseGame
{
public:
	Game(void);

	virtual void Update(GameTime*);
	virtual void Draw(GameTime*);

	~Game(void);
};

