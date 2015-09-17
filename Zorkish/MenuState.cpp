//------------------------------------------------------------------
//Menu State
//------------------------------------------------------------------
#pragma once
#include "MenuState.h"

MenuState MenuState::m_MenuState;

void MenuState::Initialise()
{
	std::ifstream file("content_menu.txt");
	std::string str;
	while (std::getline(file, str))
	{
		m_content += str;
		m_content.push_back('\n');
	}
	std::cout << m_content;
}

void MenuState::HandleInput(StateManager* game)
{
	std::cin.clear();
	char c = ' ';
	c = std::cin.peek();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (isalpha(c))
	{
		m_input = tolower(c);
	}else
	if (isalnum(c))
	{
		m_input = c;
	}
}

void MenuState::Update(StateManager* game)
{
	switch (m_input)
	{
	case '5':
		game->PushState(QuitState::Instance());
		break;
	case '4':
		game->PushState(AboutState::Instance());
		break;
	case '1':
		game->PushState(SelectState::Instance());
		break;
	case '2':
		game->PushState(HoFState::Instance());
		break;
	default:
		m_output = "Please enter a valid command";
		break;
	}
}

void MenuState::Render()
{
	std::cout << m_output << std::endl;
	std::cout << m_content;
}