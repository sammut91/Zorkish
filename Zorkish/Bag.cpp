#include "Bag.h"
Bag::Bag()
{
	Initialise("chest", "chest", "An empty chest");
}

Bag::~Bag()
{
}

void Bag::Initialise(std::string id, std::string name, std::string desc)
{
	m_description = desc;
	m_name = name;
	m_identifier = id;
	m_inventory = new Inventory("The "+ name + "'s inventory");
	m_inventory->AddItem(new Item());
	for (int i = 0; i < m_inventory->GetItems().size(); i++)
	{
		m_inventory->GetItems().at(i)->Initialise("iPhone", "iPhone", "What is this doing here?");
	}

}

void Bag::Initialise(std::vector<std::string> &splitstring)
{
	if (!(splitstring.empty()))
	{
		while (splitstring.back() != "ItemName")
		{
			if (splitstring.back() == ";")
				splitstring.pop_back();
			m_identifier.append(splitstring.back());
			splitstring.pop_back();
		}
		while (splitstring.back() != "ItemDesc")
		{
			if (splitstring.back() == "ItemName")
				splitstring.pop_back();
			m_name.append(splitstring.back() + " ");
			splitstring.pop_back();
		}
		while (splitstring.back() != ";")
		{
			if (splitstring.back() == "ItemDesc")
				splitstring.pop_back();
			m_description.append(splitstring.back());
			splitstring.pop_back();
		}
	}
}

bool Bag::AreYou(std::string id)
{
	if (m_identifier == id)
		return true;
	else
		return false;
}

std::string Bag::SendMessage(std::string msg)
{
	return 0;
}
