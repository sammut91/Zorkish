//------------------------------------------------------------------
// Hall Of Fame State
//------------------------------------------------------------------

#pragma once
#include "HoFState.h"
#include <fstream>
#include <iostream>
HoFState HoFState::m_HoFState;

void HoFState::Initialise()
{
	if (m_firstInit)
	{
		std::ifstream file("content_fame.txt");
		std::string str;
		while (std::getline(file, str))
		{
			m_content += str;
			m_content.push_back('\n');
		}
		m_firstInit = false;
	}
}

void HoFState::HandleInput(StateManager* game)
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

void HoFState::Update(StateManager* game)
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

void HoFState::Render()
{
	std::cout << m_content;
}