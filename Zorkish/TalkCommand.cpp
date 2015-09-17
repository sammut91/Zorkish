#include "TalkCommand.h"

TalkCommand TalkCommand::m_talkCommand;

std::string TalkCommand::Execute(Player &p, std::vector<std::string> input)
{
	std::string response;
	std::string sentence;
	if (!input.empty())
	{
		if (input.size() >= 4)
		{
			if (p.Locate(input.back()) != NULL)
			{
				if ((input.at((input.size() - 2)) == "to"))
				{
					for (int i = 0; i < input.size(); i++)
					{
						if (i != 0 && i != input.size()-1 && i != (input.size() - 2))
						{
							sentence.append(input.at(i));
						}
					}
					return p.SendMessage(sentence, input.back());
				}
				else
					return "Unable to say that";
			}
			return "Cannot find " + input.back();
		}
		else if (input.size() == 3)
		{
			response.append("In your inventory: \n");
			for (int i = 0; i < p.GetInventory()->GetItems().size(); i++)
			{
				response.append(p.GetInventory()->GetItems().at(i)->SendMessage(input.back()));
			}
			response.append("\n\nIn your location: \n" + p.GetLocation().SendMessage(input.back()));
			for (int i = 0; i < p.GetLocation().GetInventory()->GetItems().size()-1; i++)
			{
				response.append(p.GetLocation().GetInventory()->GetItems().at(i)->SendMessage(input.back()));
			}
		return response;
		}
	}
	return "Please enter a valid message";
}

std::vector<std::string> TalkCommand::SplitString(std::string msg)
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

bool TalkCommand::AreYou(std::string id)
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

void TalkCommand::AddIdentifier(std::string id)
{
	if (!(std::find(m_ids.begin(), m_ids.end(), id) != m_ids.end()))
	{
		m_ids.push_back(id);
	}
}
