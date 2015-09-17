/*------------------------------------------------------------------
Adventure Class
	Controls the initialisation of the aadvetnure by reading in
	from a text file.
	Loads the player class.
//-----------------------------------------------------------------*/
#pragma once
#include "Player.h"
#include "Location.h"
#include <algorithm>
#include <vector>
class Adventure
{
public:
	Adventure();
	~Adventure();

	//Startups
	void Initialise(char adventureNumber);
	void AddLocation(Location* l);
	std::vector<std::string> ReadInFromFile(std::string fileName);
	int LineAmt(std::string fileName);

	//getters
	std::vector<std::string> GetPathList(){ return m_player.GetLocation().PathList(); }
	//Player GetPlayer(){ return m_player; }
	Player m_player;

	
private:
	//static Player m_player;
	std::vector<Location*> m_locations;

};

