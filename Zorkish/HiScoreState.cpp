//------------------------------------------------------------------
// Hi-Score State
//		Where the player is able to input there name after the game
//------------------------------------------------------------------
#pragma once
#include "HiScoreState.h"
#include <fstream>
#include <iostream>

HiScoreState HiScoreState::m_HiScoreState;

void HiScoreState::Initialise()
{
	if (m_firstInit)
	{
		//local values of player score name
		std::string playerName;
		std::ifstream file("content_score.txt");
		std::string str;

		while (std::getline(file, str))
		{
			m_content += str;
			m_content.push_back('\n');
		}
		m_firstInit = false;
	}
}

void HiScoreState::HandleInput(StateManager* game)
{
	std::cin.clear();
	char c = ' ';
	c = std::cin.peek();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (isalpha(c))
	{
		m_input = tolower(c);
	}
}

void HiScoreState::Update(StateManager* game)
{
	switch (m_input)
	{
	case 'm':
		game->PopState();
		break;
	case '\0':
		game->PopState();
		break;
	default:
		m_output = "Please enter a valid command";
		break;
	}
}

void HiScoreState::Render()
{
	std::cout << m_content;
}