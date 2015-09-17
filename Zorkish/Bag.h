#pragma once
#include "Item.h"
#include "Inventory.h"
class Bag :
	public Item, public Inventory
{
public:
	Bag();
	~Bag();

	std::string GetName(){ return m_name; }
	std::string GetDescription() { return m_description; }
	std::string GetId() { return m_identifier; }
	Inventory* GetInventory(){ return m_inventory; }

	void Initialise(std::string id, std::string name, std::string desc);
	void Initialise(std::vector <std::string> &splitstring);

	bool AreYou(std::string id);
	//messaging system
	std::string SendMessage(std::string msg);

private:
	Inventory* m_inventory;

	std::string m_identifier;
	std::string m_name;
	std::string m_description;
};

