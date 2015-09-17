#pragma once
#include "StateManager.h"
#include <string>
class GameState
{
public:
	virtual void Initialise() = 0;
	virtual void HandleInput(StateManager* game) = 0;
	virtual void Update(StateManager* game) = 0;
	virtual void Render() = 0;
protected:
	GameState() {}
};

