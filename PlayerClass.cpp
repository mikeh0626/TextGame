#include "stdafx.h"
#include "PlayerClass.h"


using namespace std;

PlayerClass::PlayerClass()
{
}


PlayerClass::PlayerClass(const string& player_name)
	:playerName(player_name)
{

}


PlayerClass::~PlayerClass()
{
}


void PlayerClass::setPlayerName(const string& player_name)
{
	playerName = player_name;
}


const string& PlayerClass::getPlayerName() const
{
	return playerName;
}

void PlayerClass::setCurrentRoom(const Room* Cposition)
{
	position = Cposition;
}

const Room* PlayerClass::GetCurrentRoom() const
{
	return position;
}

void PlayerClass::AddItem(const Item* item)
{
	m_items.push_back(const_cast<Item* >(item));
}

bool PlayerClass::HasWeapon()
{
	bool hasWeapon = false;

	for (const Item* item : m_items)
	{
		const Sword* sword = dynamic_cast<const Sword*>(item);
		if (sword != nullptr)
		{
			hasWeapon = true;
			break;
		}
	}
	return hasWeapon;
}