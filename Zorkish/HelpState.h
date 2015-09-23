#pragma once
#include "GameState.h"
#include "StateManager.h"
#include <iostream>
#include "MenuState.h"
#include <fstream>

class HelpState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();
	static HelpState* Instance(){
		return &m_HelpState;
	}

	std::string GetContent(){ return m_content; }

protected:
	HelpState() {}
private:
	static HelpState m_HelpState;
	std::string m_content;
	std::vector<std::string> m_split_content;
	bool m_firstInit = true;
	std::string m_output;
	char m_input = 0;

};
