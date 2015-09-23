#include "PutCommand.h"

PutCommand PutCommand::m_putCommand;

std::string PutCommand::Execute(Player &p, std::vector<std::string> input)
{
	if (input.size() == 2)
	{
		if (p.GetInventory()->Fetch(input.back()) != NULL)
		{
			Item* obj = p.GetInventory()->Take(input.back());
			p.GetLocation().GetInventory()->AddItem(obj);
			if (input.front() == "drop")
				return "Dropped " + input.back();
			return "Put " + input.back() + " in " + p.GetLocation().GetName();
		}
		else return "Cannot put " + input.back() + " anywhere / " + input.back() + " does not exist";
	}
	else if (input.size() == 4)
	{
		if (input.back()+" " == p.GetLocation().GetName())
		{
			if (p.GetInventory()->Fetch(input[1]) != NULL)
			{
				Item* obj = p.GetInventory()->Take(input[1]);
				p.GetLocation().GetInventory()->AddItem(obj);
				if (input.front() == "drop")
					return "Dropped " + input.back();
				return input[1] + " has been put in " + p.GetLocation().GetName();
			}
			else
				return "Cannot put " + input[1] + " anywhere / " + input.back() + " does not exist";
		}
		else if ((p.Locate(input.back()) != NULL))
		{
			Bag* container = dynamic_cast<Bag*>(p.Locate(input.back()));
			if (container != NULL)
			{
				if (p.GetInventory()->Fetch(input[1]) != NULL)
				{
					Item* obj = p.GetInventory()->Take(input[1]);
					container->AddItem(obj);
					return "Putting " + input[1] + " into the " + container->GetName();
				}
				else 
					return "Cannot put " + input[1] + " anywhere / " + input.back() + " does not exist";
			}
			else
				return "Cannot put inside " + input.back();
		}
		else
			return "Cannot put " + input[1] + " in " + input.back();
	}
	else
		return "Please enter a valid put command";

}

std::vector<std::string> PutCommand::SplitString(std::string msg)
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

bool PutCommand::AreYou(std::string id)
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

void PutCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}