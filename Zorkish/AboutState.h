#pragma once
#include "GameState.h"
#include "StateManager.h"
#include <iostream>
#include "MenuState.h"
#include <fstream>

class AboutState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();

	static AboutState* Instance(){
		return &m_AboutState;
	}

	std::string GetContent(){ return m_content; }

protected:
	AboutState() {}
private:
	//members
	static AboutState m_AboutState;
	bool m_firstInit = true;
	std::string m_content;
	std::string m_output;
	char m_input = 0;
};

