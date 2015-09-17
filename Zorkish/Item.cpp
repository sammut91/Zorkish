#include "Item.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Initialise(std::vector<std::string> &splitstring)
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
			m_description.append(splitstring.back()+" ");
			splitstring.pop_back();
		}
	}
}


void Item::Initialise(std::string id, std::string name, std::string desc)
{
	m_description = desc;
	m_name = name;
	m_identifier = id;
}

std::string Item::SendMessage(std::string msg)
{
	if (msg == "identify")
	{
		return GetDescription();
	}else
	if (msg.find("flammable") != std::string::npos)
	{
		if (isFlammable())
		{
			return m_name + " is " + "flammable \n";
		}
		else
			return m_name + " isn't " + "flammable \n";
	}else
	if (msg == "hi")
	{
		return m_name + " cannot talk";
	}
	else
		return "Invalid message";

}

bool Item::AreYou(std::string id)
{
	if (m_identifier == id)
		return true;
	else
		return false;
}
