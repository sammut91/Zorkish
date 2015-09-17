#pragma once
#include "Item.h"
#include <string>
#include <list>
class Inventory:
	public IdentifiableObject
{
public:
	Inventory();
	Inventory(std::string desc);
	~Inventory();

	//functions
	void AddItem(Item* itm);
	Item* Take(std::string id);
	bool HasItem(std::string itm);
	Item* Fetch(std::string id);
	
	//getters
	std::string GetId(){ return m_identifer; }
	std::string GetName() { return m_name; }
	std::string GetDescription(){ return m_description; }
	std::string SendMessage(std::string msg);

	bool AreYou(std::string id);
	std::string GetItemList();
	std::vector<Item*> GetItems(){ return m_items; }

private:
	std::vector<Item*> m_items;
	std::string m_itemList;

	std::string m_name;
	std::string m_identifer;
	std::string m_description;

};

