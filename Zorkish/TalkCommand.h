#pragma once
#include "Command.h"
class TalkCommand :
	public Command
{
public:
	static TalkCommand* Instance(){ return &m_talkCommand; }
	std::string GetId(){ return m_name; }
	std::string Execute(Player &p, std::vector<std::string> input);
	std::vector<std::string> SplitString(std::string msg);
	bool AreYou(std::string id);
	void AddIdentifier(std::string);
protected:
	TalkCommand(){}
private:
	static TalkCommand m_talkCommand;
	std::string m_name = "talk";
	std::vector<std::string> m_ids;
};

