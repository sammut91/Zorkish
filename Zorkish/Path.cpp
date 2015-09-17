#include "Path.h"


Path::Path()
{
}


Path::~Path()
{
}

//Intiialise the paths with strings
//In order with the locations setup (number of paths == total number of paths in locations)
void Path::Initialise(std::vector<std::string> &splitstring)
{
	if (!(splitstring.empty()))
	{
		while (splitstring.back() != "PathName")
		{
			if (splitstring.back() == ";")
				splitstring.pop_back();
			m_identifier.append(splitstring.back() + " ");
			splitstring.pop_back();
		}
		while (splitstring.back() != "PathDesc")
		{
			if (splitstring.back() == "PathName")
				splitstring.pop_back();
			m_name.append(splitstring.back() + " ");
			splitstring.pop_back();
		}
		while (splitstring.back() != "PathDest")
		{
			if (splitstring.back() == "PathDesc")
				splitstring.pop_back();
			m_description.append(splitstring.back() + " ");
			splitstring.pop_back();
		}

		while (splitstring.back() != ";")
		{
			if (splitstring.back() == "PathDest")
				splitstring.pop_back();
			m_destinationName.append(splitstring.back());
			splitstring.pop_back();
		}
	}
	
}

std::string Path::SendMessage(std::string msg)
{
	return 0;
}

bool Path::AreYou(std::string id)
{
	if (m_identifier == id+" ")
		return true;
	else
		return false;
}

void Path::SetDestination(Location* l)
{
	m_destination = l;
}