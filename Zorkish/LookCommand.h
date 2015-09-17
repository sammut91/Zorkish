#pragma once
#include "Command.h"
#include <typeinfo>
class LookCommand :
	public Command
{
public:
	static LookCommand* Instance(){ return &m_lookCommand; }
	std::string GetId(){ return m_name; }
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	bool AreYou(std::string id);
	void AddIdentifier(std::string);
protected:
	LookCommand(){}
private:
	static LookCommand m_lookCommand;
	std::string m_name = "look";
	std::vector<std::string> m_ids;
};

