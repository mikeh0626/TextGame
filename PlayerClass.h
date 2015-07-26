#pragma once

#include "Entity.h"
#include "Room.h"
#include "Item.h"
#include "Sword.h"
class Room;
class PlayerClass
	: public Entity
{
private:
	//player name and position
	const Room* position;
	std::string playerName;

	using Items = std::vector < Item* > ;
	Items m_items;

public:
	PlayerClass();
	PlayerClass(const std::string& player_Name);

	void AddItem(const Item* item);
	bool HasWeapon();
	//dconstructor
	~PlayerClass();


	void setPlayerName(const std::string& player_Name);


	const std::string& getPlayerName() const;

	void setCurrentRoom(const Room* pCurrentposition);
	const Room* GetCurrentRoom() const;
};



