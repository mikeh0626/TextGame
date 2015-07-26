#pragma once
#include <sstream>
#include "MoveOption.h"
#include "QuitOption.h"

class Game
{
public:


	Game();
	~Game();
	void RunGame();


private:
	static const unsigned int m_numberOfRooms = 4;
	using Rooms = std::array < Room, m_numberOfRooms> ;
	Rooms m_rooms;

	PlayerClass m_player;
	
	MoveOption m_moveNorthOption;
	MoveOption m_moveEastOption;
	MoveOption m_moveSouthOption;
	MoveOption m_moveWestOption;
	QuitOption m_quitOption;

	Sword m_sword;
		
	static const unsigned int m_numberOfOptions = 5;
	Option* m_options[m_numberOfOptions];

	void InitializeRooms();
	void WelcomePlayer();
	void GivePlayerOptions() const;
	void GetPlayerInput(std::string& option);
	void UpdateOnOption(playerOptions selectedOption);
	playerOptions EvaluateInput(std::string& playerInput);
};
