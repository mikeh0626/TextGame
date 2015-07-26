#pragma once
#include "Option.h"
class MoveOption :
	public Option
{

private:
	Room::JoiningDirections m_directionToMove;


public:
	MoveOption();
	MoveOption(Room::JoiningDirections joiningDirection, playerOptions chosenOption,
		const std::string& outputText);

	~MoveOption();

	bool Evaluate(const std::string& optionText, PlayerClass& player);

};

