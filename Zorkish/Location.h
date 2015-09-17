#pragma once
#include "IdentifiableObject.h"
#include <vector>
#include "Item.h"
#include "Bag.h"
#include "Inventory.h"
#include <algorithm>
#include "Path.h"
#include <fstream>
#include <sstream>

//forward declerataions 
class Path;

class Location:
	public IdentifiableObject
{
public:
	Location();
	~Location();

	//getters
	std::string GetName(){ return m_name; }
	std::string GetDescription() { return m_description; }
	std::string GetId() { return m_identifier; }
	Location GetLocation(std::string locName);
	std::vector<Path*> GetPathList(){ return m_paths; }

	//startups
	void Initialise(std::vector<std::string> &splitstring);
	void InitialisePaths(std::vector<std::string>splitstring, std::vector<::Location*> &locations);
	void InitialiseInventory(std::vector<std::string> &splitstring);
	void AddPath(Path* p);
	bool AreYou(std::string id);
	Inventory* GetInventory(){ return m_inventory; }

	//functions
	std::string SendMessage(std::string msg);
	std::vector<std::string> PathList();
	std::string GetInformation();
	std::string Paths();
	

private:
	//members
	int m_pathAmount;
	std::vector<std::string> m_pathList;
	std::string m_identifier;
	std::string m_name;
	std::string m_description;
	std::vector<Path*> m_paths;

	//items in the location
	Inventory* m_inventory;
	int m_itemAmount;

};

