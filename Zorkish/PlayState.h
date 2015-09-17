//------------------------------------------------------------------
//Play State
//	The main state that the player will be in.
//	Controls the main part of the game loop, all messages will be run
//		here.
//------------------------------------------------------------------
#pragma once
#include "GameState.h"
#include "Player.h"
#include <vector>
#include "CommandManager.h"
#include "StateManager.h"
#include <iostream>
#include <string>
#include "HiScoreState.h"
#include <fstream>
#include <sstream>
#include "Adventure.h"

class PlayState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();
	static PlayState* Instance(){
		return &m_PlayState;
	}

	std::string GetContent(){ return m_content; }

protected:
	PlayState() {}
private:
	static PlayState m_PlayState;
	std::string m_content;
	std::vector<std::string> m_split_content;
	std::string m_output;
	bool m_firstInit = true;
	char m_input = 0;
	

	//Adventure Controller
	Adventure m_adventure;
	std::string m_adventureFile;

};
