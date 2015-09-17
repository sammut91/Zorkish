//------------------------------------------------------------------
//Player Class
//------------------------------------------------------------------

#pragma once
#include "Player.h"
Player::Player()
{

}

Player::~Player()
{
}


//initialise the players starting information and items
void Player::Initialise(Location* l)
{
	m_name = "player";
	m_identifier = "player";
	m_description = "The Player";

	//set the players location
	m_location = *l;
	Item* itm1 = new Item();
	Bag* itm2 = new Bag();
	itm2->Initialise("bag", "bag", "The players bag");
	itm1->Initialise("sword", "a sword", "A wooden sword");
	m_inventory = new Inventory();
	m_inventory->AddItem(itm1);
	m_inventory->AddItem(itm2);
}

std::string Player::SendMessage(std::string msg)
{
	if (msg == "greet")
	{
		return "Hi there!";
	}
}

bool Player::AreYou(std::string id)
{
	if (m_identifier == id)
		return true;
	else
		return false;
}

//moves the player to the desired location by checking the paths destinations
void Player::MoveTo(std::string location)
{
	for (auto element : m_location.GetPathList())
	{
		if (element->GetDestination()->AreYou(location))
		{
			m_location = *element->GetDestination();
		}
	}
}

void Player::MoveDirection(std::string direction)
{
	for (auto element : m_location.GetPathList())
	{
		if (element->AreYou(direction))
		{
			m_location = *element->GetDestination();
		}
	}
}

//returns a poiner to an object that the player is trying to find
IdentifiableObject* Player::Locate(std::string id, std::string containerId)
{
	if (AreYou(id))
	{
		return this;
	}
	else if (m_inventory->AreYou(containerId)){
		if (m_inventory->Fetch(id) != NULL)
		{
			Item* a = m_inventory->Fetch(id);
			IdentifiableObject* c = a;
			return c;
		}
		else
			return NULL;
	}
	else
	{
		Bag* obj = dynamic_cast<Bag*>(m_inventory->Fetch(containerId));
		if (obj != NULL)
		{
			return obj->Fetch(id);
		}
		return NULL;
	}



}
IdentifiableObject* Player::Locate(std::string id)
{
	if (AreYou(id))
	{
		return this;
	}
	else
	if (m_inventory->AreYou(id))
		return m_inventory;
	else if (m_location.AreYou(id))
	{
		return &m_location;
	}
	for (int i = 0; i < m_location.GetInventory()->GetItems().size(); i++)
	{
		if (m_location.GetInventory()->GetItems().at(i)->AreYou(id))
		{
			return m_location.GetInventory()->GetItems().at(i);
		}
	}
	// add location inventory search here
	for (int i = 0; i < m_location.GetPathList().size(); i++)
	{
		if ((m_location.GetPathList().at(i)->AreYou(id)))
		{
			return m_location.GetPathList().at(i);
		}
	}
	return NULL;
}

Bag* Player::LocateContainer(std::string id)
{
	for (int i = 0; i < m_inventory->GetItems().size(); i++)
	{
		if (m_inventory->GetItems().at(i)->AreYou(id))
		{
			return dynamic_cast<Bag*>(m_inventory->GetItems().at(i));
		}
	}

	for (int i = 0; i < m_location.GetInventory()->GetItems().size(); i++)
	{
		if (m_location.GetInventory()->GetItems().at(i)->AreYou(id))
		{
			//return m_inventory->GetItems().at(i);
		}
	}
	return NULL;
}


