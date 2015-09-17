//------------------------------------------------------------------
//State Manager
//------------------------------------------------------------------
#include "StateManager.h"
#include "GameState.h"


StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

// sets up the state manager
//		sets the intial running condition to true

void StateManager::Initialise()
{
	m_running = true;
	m_CommandManager.Initialise();
}

void StateManager::HandleInput()
{
	m_states.back()->HandleInput(this);
}

void StateManager::Update()
{
	m_states.back()->Update(this);
}

void StateManager::Render()
{
	m_states.back()->Render();
}

void StateManager::PushState(GameState* state)
{
	m_states.push_back(state);
	m_states.back()->Initialise();
}

//pop the last stare that was used and push the state that is passed to ChangeState onto the back
void StateManager::ChangeState(GameState* state)
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
	m_states.push_back(state);
	m_states.back()->Initialise();
}

//if the state vector isn't empty pop the last state from the back.
void StateManager::PopState()
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
}

void StateManager::SetAdventure(char adventureNumber)
{
	m_adventureNumber = adventureNumber;
}