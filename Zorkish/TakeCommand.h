#pragma once
#include "Command.h"
class TakeCommand :
	public Command
{
public:

	static TakeCommand* Instance(){ return &m_takeCommand; }
	std::string GetId(){ return m_name; }
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	bool AreYou(std::string id);
	void AddIdentifier(std::string);

protected:
	TakeCommand(){}
private:
	static TakeCommand m_takeCommand;
	std::string m_name = "take";
	std::vector<std::string> m_ids;
};
