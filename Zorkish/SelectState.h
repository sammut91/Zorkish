#pragma once
#include "GameState.h"
#include "StateManager.h"
#include <iostream>
#include "PlayState.h"
class SelectState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();
	static SelectState* Instance(){
		return &m_SelectState;
	}

	std::string GetContent(){ return m_content; }

protected:
	SelectState() {}
private:
	static SelectState m_SelectState;
	std::string m_content;
	std::vector<std::string> m_split_content;
	std::string m_output;
	char m_input = 0;
};

