#include "Inventory.h"
#include <string>

Inventory::Inventory()
{
	m_name = "inventory";
	m_identifer = "inventory";
	m_description = "Players inventory";
}

Inventory::Inventory(std::string desc)
{
	m_description = desc;
}


Inventory::~Inventory()
{
}

void Inventory::AddItem(Item* itm)
{
	m_items.push_back(itm);
}

std::string Inventory::GetItemList()
{
	std::string itemList;
	itemList.append("Contains: \n");
	if (!m_items.empty())
	{
		for (auto element : m_items)
		{
			if (m_items.back() == element)
				itemList.append("A " + element->GetName() + ": " + element->GetDescription());
			else
				itemList.append("A " + element->GetName() + ": " + element->GetDescription() + "\n");
		}
		return itemList;
	}
else
	return "The "+ m_name +" is empty";
}

Item* Inventory::Take(std::string id)
{
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items.at(i)->AreYou(id))
		{
			Item* obj = m_items.at(i);
			m_items.erase(m_items.begin()+i);
			return obj;
		}
	}
}

bool Inventory::HasItem(std::string itm)
{
	for (int i = 0; i < m_items.size(); i++)
	{
		if (m_items.at(i)->AreYou(itm))
		{
			return true;
		}
	}
}

std::string Inventory::SendMessage(std::string msg)
{
	return 0;
}

bool Inventory::AreYou(std::string msg)
{
	if (m_identifer == msg)
		return true;
	else
		return false;
}

Item* Inventory::Fetch(std::string id)
{
	for (int i = 0; i < m_items.size();i++)
	{
		if (m_items.at(i)->AreYou(id))
		{
			return m_items.at(i);
		}
	}
	return NULL;
}
