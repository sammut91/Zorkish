//------------------------------------------------------------------
//Quit State
//------------------------------------------------------------------
#pragma once
#include "QuitState.h"
#include "StateManager.h"
#include <iostream>
#include <fstream>

QuitState QuitState::m_QuitState;

void QuitState::Initialise()
{
	std::ifstream file("content_quit.txt");
	std::string str;
	while (std::getline(file, str))
	{
		m_content += str;
		m_content.push_back('\n');
	}
}

void QuitState::HandleInput(StateManager* game)
{

}

void QuitState::Update(StateManager* game)
{
	game->Quit();
}

void QuitState::Render()
{
	std::cout << m_content;
}