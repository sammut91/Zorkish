/*------------------------------------------------------------------
Alias Command
	Controls the ability to add new identifiers to commands
	during run time
//-----------------------------------------------------------------*/
#include "AliasCommand.h"

AliasCommand AliasCommand::m_AliasCommand;

std::string AliasCommand::Execute(Player &p, std::vector<std::string> input)
{
	if (!(input.empty()))
	{
		if (input.size() != 3)
			return "Please enter a valid alias command";
	}
else
	return "Invalid command";
}

std::string AliasCommand::Execute(CommandManager* cmdMgr, std::vector<std::string> input)
{
	if (!(input.empty()))
	{
		if (input.size() != 3)
			return "Please enter a valid alias command";
		cmdMgr->AddNewId(input[1], input.back());
		return "New alias [" + input.back() + "] added for the [" + input[1]
			+ "] command.";
	}
	else
		return "Invalid command";
}

std::vector<std::string> AliasCommand::SplitString(std::string msg)
{
	std::string buf;
	std::vector<std::string> splitstring;

	std::stringstream ss(msg);

	while (ss >> buf)
	{
		splitstring.push_back(buf);
	}
	return splitstring;
}

bool AliasCommand::AreYou(std::string id)
{
	if (!(m_ids.empty()))
	{
		for (auto element : m_ids)
		{
			if (element == id)
				return true;
		}
		return false;
	}
}

void AliasCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}