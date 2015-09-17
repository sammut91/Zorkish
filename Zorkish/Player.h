#pragma once
#include "IdentifiableObject.h"
#include "Inventory.h"
#include "Bag.h"
#include "Location.h"
#include <vector>
class Player :
	public IdentifiableObject
{
public:
	Player();
	~Player();

	//startups
	std::string GetName(){ return m_name; }
	std::string GetDescription() { return m_description; }
	std::string GetId() { return m_identifier; }
	void Initialise(Location* l);

	//getters
	int GetPlayerScore(){ return m_score; }
	int GetPlayerMoves() { return m_moves; }
	Location GetLocation(){ return m_location; }

	//void GetNearbyObjects(IdentifiableObject* obj);

	//functions
	std::string SendMessage(std::string msg);
	bool AreYou(std::string id);
	void MoveTo(std::string location);
	void MoveDirection(std::string direction);
	IdentifiableObject* Locate(std::string id, std::string containerId);
	IdentifiableObject* Locate(std::string id);
	Bag* LocateContainer(std::string id);

	Inventory* m_inventory;

	//get the inventory
	Inventory* GetInventory(){ return m_inventory; }
private:
	//player members
	std::string m_identifier;
	std::string m_name;
	std::string m_description;


	//score, moves and adventure
	int m_score;
	int m_moves;
	//Adventure adventure;

	//nearby Objects
	std::vector<IdentifiableObject*> m_objs;

	//location
	Location m_location;

	//inventory
	//Inventory m_inventory;
};

