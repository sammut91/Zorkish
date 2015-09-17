//------------------------------------------------------------------
//About State
//------------------------------------------------------------------
#pragma once
#include "AboutState.h"


AboutState AboutState::m_AboutState;

void AboutState::Initialise()
{
	if (m_firstInit)
	{
		std::ifstream file("content_about.txt");
		std::string str;
		while (std::getline(file, str))
		{
			m_content += str;
			m_content.push_back('\n');
		}
		m_firstInit = false;
	}
}

void AboutState::HandleInput(StateManager* game)
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

void AboutState::Update(StateManager* game)
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

void AboutState::Render()
{
	std::cout << m_content;
}