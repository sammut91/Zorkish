#pragma once
#include "GameState.h"
class HoFState :
	public GameState
{
	public:
		void Initialise();
		void HandleInput(StateManager* game);
		void Update(StateManager* game);
		void Render();

		static HoFState* Instance(){
			return &m_HoFState;
		}

		std::string GetContent(){ return m_content; }

	protected:
		HoFState() {}
	private:
		//members
		static HoFState m_HoFState;
		bool m_firstInit = true;
		std::string m_content;
		std::string m_output;
		char m_input = 0;
};
