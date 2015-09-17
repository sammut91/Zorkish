#pragma once
//------------------------------------------------------------------
//Identifiable Object
//	All objects in ZOrkish will implement these basic functions
//------------------------------------------------------------------
#pragma once
#include <string>
#include <vector>
//does this need to be virtual?
class IdentifiableObject
{
public:
	//virtual std::vector<std::string> GetId() = 0;
	virtual std::string GetId() = 0;
	virtual std::string GetName() = 0;
	virtual std::string GetDescription() = 0;
	virtual	std::string SendMessage(std::string msg) = 0;

	virtual bool AreYou(std::string id) = 0;
};

