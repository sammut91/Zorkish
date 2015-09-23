#include "QuitCommand.h"

QuitCommand QuitCommand::m_quitCommand;

std::string QuitCommand::Execute(Player &p, std::vector<std::string> input)
{
	return "Quitting the game now";
}

std::vector<std::string> QuitCommand::SplitString(std::string msg)
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

bool QuitCommand::AreYou(std::string id)
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

void QuitCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}