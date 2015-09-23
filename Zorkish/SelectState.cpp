#include "SelectState.h"

SelectState SelectState::m_SelectState;

void SelectState::Initialise()
{
	//local values for playstate initialisation
	std::ifstream file("content_play.txt");
	std::string str;

	while (std::getline(file, str))
	{
		m_content += str;
		m_content.push_back('\n');
	}

	std::cout << m_content;
}

void SelectState::HandleInput(StateManager* game)
{
	std::cin.clear();
	char c = ' ';
	c = std::cin.peek();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (isalpha(c))
	{
		m_input = tolower(c);
	}
	else
	if (isalnum(c))
	{
		m_input = c;
	}
}

void SelectState::Update(StateManager* game)
{
	switch (m_input)
	{
	case '1':
		game->SetAdventure(m_input);
		game->PushState(PlayState::Instance());
		break;
	case '2':
		game->SetAdventure(m_input);
		game->PushState(PlayState::Instance());
		break;
	case '3':
		game->SetAdventure(m_input);
		game->PushState(PlayState::Instance());
		break;
	case 'm':
		game->PopState();
	default:
		m_output = "Please enter a valid command";
		break;
	}
}

void SelectState::Render()
{
	if (m_output != "")
		std::cout << m_output << std::endl;
	m_output = "";
}