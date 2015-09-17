#pragma once
#include "GameState.h"
#include "QuitState.h"
#include "AboutState.h"
#include "PlayState.h"
#include "HoFState.h"
#include "HiScoreState.h"
#include "StateManager.h"
#include <iostream>
#include <limits>
#include <fstream>
#include "SelectState.h"
class MenuState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();

	static MenuState* Instance(){
		return &m_MenuState;
	}

	std::string GetContent(){ return m_content; }

protected:
	MenuState() {}
private:
	static MenuState m_MenuState;
	std::string m_content;
	char m_input = 0;
	std::string m_output;
};

