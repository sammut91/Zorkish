#pragma once
#include "Command.h"
class MoveCommand :
	public Command
{
public:
	static MoveCommand* Instance(){ return &m_moveCommand; }
	std::string GetId(){ return m_name; }
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	bool AreYou(std::string id);
	void AddIdentifier(std::string);
private:
	static MoveCommand m_moveCommand;
	std::string m_name = "move";
	std::vector<std::string> m_ids;
};

