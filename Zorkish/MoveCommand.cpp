#include "MoveCommand.h"

MoveCommand MoveCommand::m_moveCommand;

std::string MoveCommand::Execute(Player &p, std::vector<std::string> input)
{
	if (!(input.empty()))
	{
		if (input.size() == 2)
		{
			for (auto element : p.GetLocation().GetPathList())
			{
				if (element == p.GetLocation().GetPathList().back())
				{
					if (element->GetName() == input.back()+' ')
					{
						p.MoveDirection(input.back());
						return "Moving " + input.back();
					}
					else
						return "Cannot " + input.front() +" " + input.back();
				}
				if (element->GetName() == input.back()+' ')
				{
					p.MoveDirection(input.back());
					return "Moving " + input.back();
				}
			}
		}
		if (input.size() == 3)
		{
			for (auto element : p.GetLocation().GetPathList())
			{
				if (element == p.GetLocation().GetPathList().back())
				{
					if (element->GetDestName() == input.back())
					{
						p.MoveTo(input.back());
						return "Moving to " + input.back();
					}
					else
						return "Cannot " + input.front() + " to " + input.back();
				}
				if (element->GetDestName() == input.back())
				{
					p.MoveTo(input.back());
					return "Moving to " + input.back();
				}
			}
		}
		return "Invalid move command";
	}	
	return "Invalid move command";
}

std::vector<std::string> MoveCommand::SplitString(std::string msg)
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

bool MoveCommand::AreYou(std::string id)
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

void MoveCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}
