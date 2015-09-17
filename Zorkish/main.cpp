#include <iostream>
#include "StateManager.h"
#include "MenuState.h"

int main(int argc, char* argv)
{

	StateManager game;
	game.Initialise();
	//game.PushState(MenuState::Instance());
	//game.Initialise();
	game.ChangeState(MenuState::Instance());
	while (game.Running())
	{
		//Handles the user input via peek -- allows for a non blocking game loop
		game.HandleInput();
		//if a user enters a command bool is true
		game.Update();
		//if the bool is true then the render will take place and then set it back to false
		//other wise the render will not take place
		game.Render();
	}
	std::string l;
	std::cout << "Are you sure? Yes or No?" << std::endl;
	std::cin >> l;
	return 0;

}