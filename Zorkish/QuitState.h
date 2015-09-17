#pragma once
#include "GameState.h"
#include <string>

class QuitState :
	public GameState
{
public:
	void Initialise();
	void HandleInput(StateManager* game);
	void Update(StateManager* game);
	void Render();

	static QuitState* Instance(){
		return &m_QuitState;
	}

	std::string GetContent(){ return m_content; }

protected:
	QuitState() {}
private:
	static QuitState m_QuitState;
	std::string m_content;
};

