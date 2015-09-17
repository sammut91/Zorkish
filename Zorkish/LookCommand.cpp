#include "LookCommand.h"

LookCommand LookCommand::m_lookCommand;

std::string LookCommand::Execute(Player &p, std::vector<std::string> input)
{
	if (!(input.empty()))
	{
		std::transform(input.back().begin(), input.back().end(), input.back().begin(), ::tolower);
		if (input.size() == 1)
		{
			return "What do you want to " + input.back() + " at?";
		}
		else if (input.size() == 2)
		{
			if (input.back() == "around")
			{
				return p.GetLocation().GetDescription() + "\n" + p.GetLocation().GetInventory()->GetItemList() + "\n\n"
					+ p.GetLocation().Paths();
			}
			if (p.Locate(input.back()) != NULL)
			{
				return p.Locate(input.back())->GetDescription();
			}
			else
				return "Cannot look " + input.back();
		}
		else if (input.size() == 3)
		{
			if (input[1] == "in" && input.back() == "inventory")
			{
				return p.GetInventory()->GetItemList();
			}
			else if (input.back() == "location")
			{
				return p.GetLocation().GetDescription() +"\n" + p.GetLocation().GetInventory()->GetItemList() + "\n\n" 
					+ p.GetLocation().Paths();
			}
			else if (p.Locate(input.back()) != NULL)
			{
				Bag* obj = dynamic_cast<Bag*>(p.Locate(input.back()));
				if (obj != NULL)
					return obj->GetDescription() + "\n" + obj->GetItemList();
				else
					return p.Locate(input.back())->GetDescription();
			}
			else
				return "Cannot locate " + input.back();
			
		}
		else if (input.size() == 5)
		{
			if (input[3] == "in")
			{
				if (p.Locate(input[2], input.back()) != NULL)
				{
					return p.Locate(input[2], input.back())->GetDescription();
				}
				else
					return "Cannot find " + input[2] + " in " + input.back();
			}
			else
				return "Do you want to look in the " + input.back();
		}
	}
}

std::vector<std::string> LookCommand::SplitString(std::string msg)
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

bool LookCommand::AreYou(std::string id)
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

void LookCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}
