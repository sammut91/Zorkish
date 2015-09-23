//------------------------------------------------------------------
//Play State
//	- This state contains the game loading and handling of the main
//		player input for the game.
//	- A player enters a command they wish to process and the 
//		command manager will check with its commands and execute the 
//		appropriate command.
//------------------------------------------------------------------
#pragma once
#include "PlayState.h"


PlayState PlayState::m_PlayState;

void PlayState::Initialise()
{
	if (m_firstInit)
	{
		m_adventure.Initialise('1');

		//local values for playstate initialisation
		m_adventureFile = "content_mountain.txt";
		std::ifstream file(m_adventureFile);
		std::string str;
		
		while (std::getline(file, str))
		{
			m_content += str;
			m_content.push_back('\n');
		}		

		std::cout << m_content;
		m_firstInit == false;
	}	
}

void PlayState::HandleInput(StateManager* game)
{
	m_split_content.clear();
	std::string input;
	std::string buf;
	std::vector<std::string> splitstring;

	std::getline(std::cin, input);
	std::stringstream ss(input);
	
	while (ss >> buf)
	{
		splitstring.push_back(buf);
	}
	m_split_content = splitstring;
}

void PlayState::Update(StateManager* game)
{
	if (!m_split_content.empty())
	{
		if (m_split_content.front()== "1" && m_firstInit)
		{
			//m_adventure.Initialise("1");
		}else
		if (m_split_content.front() == "2"&& m_firstInit)
		{
			//m_adventure.Initialise("2");
		}else
		if (m_split_content.front() == "3"&& m_firstInit)
		{
			//m_adventure.Initialise("3");
		}
		else if (m_split_content.front() == "location")
		{
			//m_output = m_adventure.m_player.GetLocation().
		}
		else if (m_split_content.front() == "inventory")
		{
			m_output = m_adventure.m_player.GetInventory()->GetItemList();
		}
		else if (m_split_content.front() == "help")
		{
			game->PushState(HelpState::Instance());
		}
		else if (m_split_content.front() == "quit")
		{
			game->PushState(QuitState::Instance());
		}
		else
			m_output = game->GetCommandManager().Execute(m_adventure.m_player,m_split_content);
	}
}

void PlayState::Render()
{
	if (m_output != "")
		std::cout << m_output << std::endl;
	m_output = "";
}
