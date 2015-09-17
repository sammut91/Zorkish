#pragma once
#include <vector>
#include "CommandManager.h"

class GameState;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void Initialise();
	void HandleInput();
	void Update();
	void Render();
	void SetAdventure(char adventureNumber);
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	//get the adventure number
	char GetAdventureNumber(){ return m_adventureNumber; }

	bool Running(){
		return m_running;
	}

	void Quit(){
		m_running = false;
	}

	CommandManager GetCommandManager(){ return m_CommandManager; }

private:
	std::vector<GameState*> m_states;
	//GameState* m_current_state = nullptr;
	//check whether the user has actually entered anything this update
	bool m_user_input = false;
	//bool to control whether or not the game is running
	bool m_running = true;
	CommandManager m_CommandManager;

	//which game file is to be loaded in?
	char m_adventureNumber;
	
};

