#pragma once
#include "Command.h"
#include "CommandManager.h"
class CommandManager;

class AliasCommand :
	public Command
{
public:
	static AliasCommand* Instance(){ return &m_AliasCommand; }
	std::string GetId(){ return m_name; }
	bool AreYou(std::string id);
	std::string Execute(Player &p, std::vector<std::string> input);
	std::string Execute(CommandManager* cmdMgr, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	void AddIdentifier(std::string);
protected:
	AliasCommand(){}
private:
	static AliasCommand m_AliasCommand;
	std::string m_name = "alias";
	std::vector<std::string> m_ids;
};
