#include "stdafx.h"
#include "Room.h"

//initialize all rooms to be empty
Room::Room()
{
	for (unsigned int i = 0; i < static_cast<unsigned int>(JoiningDirections::Max); i++)
	{
		m_pJoiningRooms[i] = nullptr;
	}
}


//add a room to the corresponding direction in current array 
void Room::AddRoom(JoiningDirections direction, Room* pRoom)
{
	m_pJoiningRooms[static_cast<unsigned int>(direction)] = pRoom;
}

//return room at direction from loocation
Room* Room::GetRoom(JoiningDirections direction) const
{
	return m_pJoiningRooms[static_cast<unsigned int>(direction)];
}

/*void Room::PrintOptions() const
{
	for (unsigned int i = 0; i < m_dynamicOptions.size(); ++i)
	{
		const Option* option = m_dynamicOptions[i];
		std::cout << i + 1 << ": " << option->GetOutputText() << std::endl << std::endl;
	}

	for (StaticOptions::const_iterator iter = m_staticOptions.cbegin();
		iter != m_staticOptions.cend();
		++iter)
	{
		const Option* option = iter->second;
		const unsigned int chosenOption = iter->first + m_dynamicOptions.size();
		std::cout << chosenOption << ": " << option->GetOutputText << std::endl << std::endl;
	}
}


Option* Room::EvaluateInput(unsigned int playerInput)
{
	Option* option = nullptr;
	const unsigned int numDynamicOptions = m_dynamicOptions.size();
	if (playerInput <= numDynamicOptions)
	{
		unsigned int dynamicIndex = playerInput - 1;
		option = m_dynamicOptions[dynamicIndex];
		m_dynamicOptions.erase(m_dynamicOptions.begin() + dynamicIndex);
	}
	else
	{
		option = m_staticOptions.at(playerInput - numDynamicOptions);
	}
	return option;
}



void Room::AddStaticOption(Option* option)
{
	assert(option != nullptr);
	m_staticOptions[m_staticOptionStartKey++] = option;
}

void Room::AddDynamicOption(Option* option)
{

}*/