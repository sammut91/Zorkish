#pragma once
#include "GameState.h"
class HiScoreState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();

	static HiScoreState* Instance(){
		return &m_HiScoreState;
	}

	std::string GetContent(){ return m_content; }

protected:
	HiScoreState() {}
private:
	//members
	static HiScoreState m_HiScoreState;
	bool m_firstInit = true;
	std::string m_content;
	std::string m_output;
	char m_input = 0;
};

