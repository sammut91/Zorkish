#pragma once
#include <string>
#include "Player.h"
#include <sstream>
#include <vector>
class Command
{
public:
	virtual std::string Execute(Player &p, std::vector<std::string> input) = 0;
	bool virtual AreYou(std::string) = 0;
	virtual std::string GetId() = 0;
	virtual void AddIdentifier(std::string id) = 0;
	virtual std::vector<std::string> SplitString(std::string msg) = 0;
protected:
	Command(){}
};

