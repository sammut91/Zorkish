#pragma once
#include "Command.h"

class QuitCommand :
	public Command
{
public:
	static QuitCommand* Instance(){ return &m_quitCommand; }
	std::string GetId(){ return m_name; }
	bool AreYou(std::string id);
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	void AddIdentifier(std::string);
protected:
	QuitCommand(){}
private:
	static QuitCommand m_quitCommand;
	std::string m_name = "quit";
	std::vector<std::string> m_ids;
};