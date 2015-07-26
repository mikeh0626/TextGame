#pragma once

#include "Entity.h"
#include <vector>
#include <array>
#include <map>
#include <assert.h>
#include <iostream>
#include <string>
#include "Option.h"

class Option;
class Room
	: public Entity
{

public:
	enum class JoiningDirections
	{
		North = 0,
		East,
		South,
		West,
		Max

	};

	Room();

	void AddRoom(JoiningDirections direction, Room* pRoom);
	Room* GetRoom(JoiningDirections direction) const;
	

	/*void Room::AddStaticOption(Option* option);
	void Room::AddDynamicOption(Option* option);
	void Room::PrintOptions() const;
	Option* Room::EvaluateInput(unsigned int playerInput);*/
private:

	//Room* m_pJoiningRooms[static_cast<unsigned int>(JoiningDirections::Max)];
	using JoiningRooms = std::array < Room*, static_cast<size_t>(JoiningDirections::Max) > ;
	JoiningRooms m_pJoiningRooms;
	
	
	using StaticOptions = std::map <unsigned int, Option* > ;
	/*StaticOptions m_staticOptions;
	unsigned int m_staticOptionStartKey{ 1 };


	using DynamicOptions = std::vector < Option* > ;
	DynamicOptions m_dynamicOptions;*/
};