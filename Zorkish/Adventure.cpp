#include "Adventure.h"


Adventure::Adventure()
{
}


Adventure::~Adventure()
{
}


/*-------------------------------------------------------------------------------
This is the function that initialises the main part of the game from text files

	-It first adds all the amount of locations depending on the lines in text file
	-Initialises these locations using the text file
	-After the locations are all set up, connect them all with paths 
	-Initialise the player entity and set its location to the first location

-------------------------------------------------------------------------------*/
void Adventure::Initialise(char adventureNumber)
{
	int locationLines = LineAmt("locations_setup.txt");
	//text file for locations and paths
	std::string locSetup;
	std::string pathSetup;
	std::string itemSetup;

	switch (adventureNumber)
	{
	case '1':
		locSetup = "locations_setup.txt";
		pathSetup = "path_setup.txt";
		itemSetup = "item_setup.txt";
		break;
	case '2':
		locSetup = "locations_setup_2.txt";
		pathSetup = "path_setup_2.txt";
		itemSetup = "item_setup.txt";
		break;
	case '3':
		locSetup = "locations_setup_3.txt";
		pathSetup = "path_setup_3.txt";
		itemSetup = "item_setup.txt";
		break;
	default:
		break;
	}
	std::vector<std::string> locInput = ReadInFromFile(locSetup);
	std::vector<std::string> pathInput = ReadInFromFile(pathSetup);
	std::vector<std::string> itemInput = ReadInFromFile(itemSetup);

	//Add in the locations
	for (int i = 0; i < locationLines; i++)
	{
		AddLocation(new Location());
	}

	//Initalise all the locations before paths are set up
	for (unsigned int i = 0; i < m_locations.size(); i++)
	{		
		m_locations.at(i)->Initialise(locInput);
	}

	//for each of the locations initialise the paths and connect them all up
	for (unsigned int i = 0; i < m_locations.size(); i++)
	{
		m_locations.at(i)->InitialisePaths(pathInput,m_locations);
	}	


	for (unsigned int i = 0; i < m_locations.size(); i++)
	{
		m_locations.at(i)->InitialiseInventory(itemInput);
	}


	for (unsigned int i = 0; i < m_locations.size(); i++)
	{
		for (int j = 0; j < m_locations.at(i)->GetInventory()->GetItems().size(); j++)
		{
			if (m_locations.at(i)->GetInventory()->GetItems().at(j)->AreYou("chest "))
			{
				Bag* obj = dynamic_cast<Bag*>(m_locations.at(i)->GetInventory()->GetItems().at(j));
				m_locations.at(i)->GetInventory()->GetItems().at(j) = obj;
			}
		}
	}

	m_player.Initialise(m_locations.front());
}

void Adventure::AddLocation(Location* l)
{
	if (!(std::find(m_locations.begin(), m_locations.end(), l) != m_locations.end()))
	{
		m_locations.push_back(l);
	}

}


std::vector<std::string> Adventure::ReadInFromFile(std::string fileName)
{
	std::ifstream file(fileName);
	std::string str;
	std::vector<std::string> input;
	std::vector<std::string> splitstring;
	while (std::getline(file, str))
	{
		file >> str;
		input.push_back(str);
	}
	for (auto element : input)
	{
		std::string buf;
		std::stringstream ss(element);

		while (std::getline(ss, buf, ','))
		{
			splitstring.push_back(buf);
		}
	}
	std::reverse(splitstring.begin(), splitstring.end());
	return splitstring;
}

int Adventure::LineAmt(std::string fileName)
{
	std::ifstream file(fileName);
	std::string str;
	int numberOfLines = 0;
	while (std::getline(file, str))
	{
		numberOfLines++;
	}
	return numberOfLines-1;
}