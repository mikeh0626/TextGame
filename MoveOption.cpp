#include "stdafx.h"
#include "MoveOption.h"
//#include <string>
//#include <iostream>

MoveOption::MoveOption(){}

MoveOption::MoveOption(Room::JoiningDirections joiningDirection, playerOptions chosenOption,
	const std::string& outputText)
	:Option(chosenOption, outputText),
	m_directionToMove(joiningDirection)

{
}


MoveOption::~MoveOption()
{
}

//moveoption's version of evalute
bool MoveOption::Evaluate(const std::string& optionText, PlayerClass& player)
{
	//variable to tell if change has been handled or not
	bool handled = false;

	if (m_optionText.compare(optionText) == 0)
	{
		const Room* pPlayerCurrentRoom = player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(m_directionToMove);

		if (pNewRoom != nullptr)
		{
			player.setCurrentRoom(pNewRoom);
			std::cout << "you have chosen to " << m_outPutText << std::endl;
		}
		else
		{
			const char* strDirection = "North";

			switch (p_choose)
			{
			case playerOptions::GoEast:
			{
				strDirection = "East";
			}
				break;
			case playerOptions::GoSouth:
			{
				strDirection = "South";
			}
				break;
			case playerOptions::GoWest:
			{
				strDirection = "West";
			}
				break;
			}
			std::cout << "There is no room to the " << strDirection << std::endl << std::endl;
		}

		handled = true;
	
	}
	return handled;
}
