#pragma once
#include "IdentifiableObject.h"
#include "flammable.h"
class Item :
	public IdentifiableObject, public Flammable
{
public:
	Item();
	~Item();

	std::string GetName(){ return m_name; }
	std::string GetDescription() { return m_description; }
	std::string GetId() { return m_identifier; }
	void Initialise(std::string id, std::string name, std::string desc);
	void Initialise(std::vector<std::string> &splitstring);
	
	bool AreYou(std::string id);
	bool isFlammable(){ return true; }
	//messaging system
	std::string SendMessage(std::string msg);

private:
	std::string m_identifier;
	std::string m_name;
	std::string m_description;
};

