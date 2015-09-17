#include "TakeCommand.h"

TakeCommand TakeCommand::m_takeCommand;

std::string TakeCommand::Execute(Player &p, std::vector<std::string> input)
{
	if (!input.empty())
	{
		if (input.size() == 2)
		{
			if (p.GetLocation().GetInventory()->Fetch(input.back()) != NULL)
			{
				Item* obj = p.GetLocation().GetInventory()->Take(input.back());
				p.m_inventory->AddItem(obj);
				return "took " + input.back();
			}
			else
				return "Cannot take " + input.back();
		}
		else if (input.size() == 4)
		{
			if (input.back() == "location")
			{
				if (p.GetLocation().GetInventory()->Fetch(input.back()) != NULL)
				{
					p.GetInventory()->AddItem(p.GetLocation().GetInventory()->Take(input.back()));
					return "took " + input.back();
				}
				else
					return "Cannot take " + input[1] + " from " + input.back();
			}
			else if (p.LocateContainer(input.back())!= NULL)
			{
				Bag* container = p.LocateContainer(input.back());
				if (container != NULL)
				{
					if (container->GetInventory()->Fetch(input[1]) != NULL)
					{
						Item* obj = p.GetLocation().GetInventory()->Take(input.back());
						p.m_inventory->AddItem(obj);
						return "took " + input.back();
					}
					else
						return "Couldn't take " + input[1];
				}
				else
					return "Cannot find " + input.back();
			}
			return "Cannot take " + input[1] + " from " + input.back();
		}
	}
	return "Please enter a valid command";
}

bool TakeCommand::AreYou(std::string id)
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

void TakeCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}

std::vector<std::string> TakeCommand::SplitString(std::string msg)
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