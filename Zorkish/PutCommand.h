#pragma once
#include "Command.h"
class PutCommand :
	public Command
{
public:
	static PutCommand* Instance(){ return &m_putCommand; }
	std::string GetId(){ return m_name; }
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	bool AreYou(std::string id);
	void AddIdentifier(std::string);
protected:
	PutCommand(){}
private:
	static PutCommand m_putCommand;
	std::string m_name = "put";
	std::vector<std::string> m_ids;
};
