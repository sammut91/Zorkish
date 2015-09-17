#pragma once
#include "IdentifiableObject.h"
#include "Location.h"

//forward declerataions 
class Location;

class Path:
	public IdentifiableObject
{
public:
	Path();
	~Path();

	//getters
	std::string GetName(){ return m_name; }
	std::string GetDescription() { return m_description; }
	std::string GetId() { return m_identifier; }
	std::string GetDestName(){ return m_destinationName; }
	Location* GetDestination(){ return m_destination; }

	//setter for location destination
	void SetDestination(Location* l);

	//startups
	void Initialise(std::vector<std::string> &splitstring);

	//functions
	bool AreYou(std::string id);
	std::string SendMessage(std::string msg);

private:
	std::string m_identifier;
	std::string m_name;
	std::string m_description;
	std::string m_destinationName;
	Location* m_destination;
};

