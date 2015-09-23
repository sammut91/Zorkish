#include "HelpState.h"

HelpState HelpState::m_HelpState;

void HelpState::Initialise()
{
	if (m_firstInit)
	{
		std::ifstream file("content_help.txt");
		std::string str;
		while (std::getline(file, str))
		{
			m_content += str;
			m_content.push_back('\n');
		}
		m_firstInit = false;
	}
}

void HelpState::HandleInput(StateManager* game)
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

void HelpState::Update(StateManager* game)
{
	switch (m_input)
	{
	case '\0':
		game->PopState();
		break;
	default:
		m_output = "Please enter a valid command";
		break;
	}
}

void HelpState::Render()
{
	std::cout << m_content;
}
