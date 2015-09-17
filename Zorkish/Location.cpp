//------------------------------------------------------------------
//Location
//------------------------------------------------------------------
#include "Location.h"

Location::Location()
{
}


Location::~Location()
{
}

void Location::Initialise(std::vector<std::string> &splitstring)
{
	m_inventory = new Inventory();
	if(!(splitstring.empty()))
	{
		while (splitstring.back() != "LocationName")
		{
			if (splitstring.back() == ";")
				splitstring.pop_back();
			m_identifier.append(splitstring.back() + " ");
			splitstring.pop_back();
		}
		while (splitstring.back() != "LocationDesc")
		{
			if (splitstring.back() == "LocationName")
				splitstring.pop_back();
			m_name.append(splitstring.back()+" ");
			splitstring.pop_back();
		}
		while (splitstring.back() != "LocationPaths")
		{
			if (splitstring.back() == "LocationDesc")
				splitstring.pop_back();
			m_description.append(splitstring.back() + " ");
			splitstring.pop_back();
		}
		while (splitstring.back() != "LocationItems")
		{
			if (splitstring.back() == "LocationPaths")
				splitstring.pop_back();
			std::string convert = splitstring.back();
			std::istringstream buffer(convert);
			int value;
			buffer >> value;
			m_pathAmount = value;
			splitstring.pop_back();			
		}
		while (splitstring.back() != ";")
		{
			if (splitstring.back() == "LocationItems")
				splitstring.pop_back();
			std::string convert = splitstring.back();
			std::istringstream buffer(convert);
			int value;
			buffer >> value;
			m_itemAmount = value;
			splitstring.pop_back();
		}
	}
}

std::string Location::SendMessage(std::string msg)
{
	if (msg == "Go")
	{
		return 0;
	}else
	if (msg == "flammable")
	{
		if (isFlammable())
		{
			return m_name + " is " + msg;
		}
		else
			return m_name + " isn't " + msg;
	}
	else
		return "Invalid message";
}

//intialise the paths for the location
void Location::InitialisePaths(std::vector<std::string> splitstring, std::vector<::Location*> &locations)
{
	for (int i = 0; i < m_pathAmount; i++)
	{
		AddPath(new Path());
	}

	//where the paths get assigned their locations
	for (auto element : m_paths)
	{
		element->Initialise(splitstring);
		for (auto locElement : locations)
		{
			if (locElement->AreYou(element->GetDestName()))
			{
				element->SetDestination(locElement);
			}
		}
	}
}

void Location::InitialiseInventory(std::vector<std::string> &splitstring)
{
	for (int i = 0; i < m_itemAmount; i++)
	{
	
		m_inventory->AddItem(new Item);
	}
	
	if (!splitstring.empty())
	{
		if (splitstring.back()+" " == m_identifier)
		{
			while (splitstring.back()+" " != "end" + m_identifier)
			{
				if (splitstring.back()+" " == m_identifier)
					splitstring.pop_back();
				for (auto itemElement : m_inventory->GetItems())
				{
					itemElement->Initialise(splitstring);
				}
				splitstring.pop_back();
			}
			splitstring.pop_back();
		}
	}
	if (m_name == "home ")
	{
		m_inventory->AddItem(new Bag());

	}

}

void Location::AddPath(Path* p)
{
	if (!(std::find(m_paths.begin(), m_paths.end(), p) != m_paths.end()))
	{
		m_paths.push_back(p);
	}
}


bool Location::AreYou(std::string id)
{
	if (m_identifier == id+" ")
		return true;
	else
		return false;
}

//prints out the list of paths available to the player
std::vector<std::string> Location::PathList()
{
	for (auto element : m_paths)
	{
		m_pathList.push_back(element->GetName() + ":" + element->GetDescription() + "To: "
			+ element->GetDestName());
	}
	return m_pathList;
}

Location Location::GetLocation(std::string locationId)
{
	if (AreYou(locationId))
	{
		return *this;
	}
}


std::string Location::GetInformation()
{
	// return m_description + "\n" + "Paths:" + "\n" + PathList();
	return 0;
}

std::string Location::Paths()
{
	std::string pathList;
	pathList.append("Paths available: \n");
	for (auto element : m_paths)
	{
		if (element == m_paths.back())
		{
			pathList.append(element->GetName() + ": " + element->GetDescription() + " Leads to: "
				+ element->GetDestName());
		}else
		pathList.append(element->GetName() + ": " + element->GetDescription() + " Leads to: "
			+ element->GetDestName() + "\n");
	}
	return pathList;
}