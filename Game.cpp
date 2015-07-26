#include "stdafx.h"
#include "Game.h"

using namespace std;
//Game class constructor initializes options class objects
Game::Game()
	:m_moveNorthOption(Room::JoiningDirections::North, playerOptions::GoNorth, "Go North")
	, m_moveEastOption(Room::JoiningDirections::East, playerOptions::GoEast, "Go East")
	, m_moveSouthOption(Room::JoiningDirections::South, playerOptions::GoSouth, "Go South")
	, m_moveWestOption(Room::JoiningDirections::West, playerOptions::GoWest, "Go West")
	, m_quitOption("Quit")
{
	m_options[0] = dynamic_cast<Option*>(&m_moveNorthOption);
	m_options[1] = dynamic_cast<Option*>(&m_moveEastOption);
	m_options[2] = dynamic_cast<Option*>(&m_moveSouthOption);
	m_options[3] = dynamic_cast<Option*>(&m_moveWestOption);
	m_options[4] = dynamic_cast<Option*>(&m_quitOption);
}

Game::~Game()
{
	cout << "game entity iss destroyed" << endl;
}


void Game::InitializeRooms()
{
	//Room 0 heads North to Room1
	m_rooms[0].AddRoom(Room::JoiningDirections::North, &(m_rooms[1]));

	//Room 1 heads East to Room 2, South to room 0 and West to Room 3
	m_rooms[1].AddRoom(Room::JoiningDirections::East, &(m_rooms[2]));
	m_rooms[1].AddRoom(Room::JoiningDirections::South, &(m_rooms[0]));
	m_rooms[1].AddRoom(Room::JoiningDirections::West, &(m_rooms[3]));

	//Room 2 heads west to room 1
	m_rooms[2].AddRoom(Room::JoiningDirections::West, &(m_rooms[1]));

	//Room 3 heads east to room 1
	m_rooms[3].AddRoom(Room::JoiningDirections::East, &(m_rooms[1]));

	m_player.setCurrentRoom(&(m_rooms[0]));
}

void Game::WelcomePlayer()
{
	cout << "Welcome to Text Adventure!" << endl << endl;
	cout << "What is your name? " << endl << endl;

	string name;
	getline(cin, name);
	m_player.setPlayerName(name);

	cout << endl << "Hello " << m_player.getPlayerName() << endl;
}

void Game::GivePlayerOptions() const
{
	cout << "What would you like to do? (Enter a corresponding number)" << endl << endl;
	for (unsigned int i = 0; i < m_numberOfOptions; i++)
	{
		Option* option = m_options[i];
		const unsigned int chosenOption = i + 1;
		cout << chosenOption << ": " << option->GetOutputText() << endl << endl;
		std::ostringstream chosenOptionString;
		chosenOptionString << chosenOption;
		option->SetOptionTxt(chosenOptionString.str());
	}
}

void Game::GetPlayerInput(string& playerInput)
{
	cin >> playerInput;
}

playerOptions Game::EvaluateInput(string& playerInput)
{
	playerOptions chosenOption = playerOptions::None;
	
	for (unsigned int i = 0; i < m_numberOfOptions; i++)
	{
		Option* option = m_options[i];
		bool handled = option->Evaluate(playerInput, m_player);
		if (handled == true)
		{
			chosenOption = option->GetChosenOption();
			break;
		}

	}
		if (chosenOption == playerOptions::None)
		{
			cout << "I do not recognize that option, try again!" << endl << endl;
		}

	
	
	return chosenOption;
}


void Game::UpdateOnOption(playerOptions selectedOption)
{
	if (selectedOption == playerOptions::GoNorth || selectedOption == playerOptions::GoEast ||
		selectedOption == playerOptions::GoSouth || selectedOption == playerOptions::GoWest)
	{
		Room::JoiningDirections directionsToMove = Room::JoiningDirections::North;

		switch (selectedOption)
		{
		case playerOptions::GoEast:
		{
			directionsToMove = Room::JoiningDirections::East;
		}
			break;

		case playerOptions::GoSouth:
		{
			directionsToMove = Room::JoiningDirections::South;
		}
			break;

		case playerOptions::GoWest:
		{
			directionsToMove = Room::JoiningDirections::West;
		}
			break;
		}

		const Room* pPlayerCurrentRoom = m_player.GetCurrentRoom();
		const Room* pNewRoom = pPlayerCurrentRoom->GetRoom(directionsToMove);

		if (pNewRoom != nullptr)
		{
			m_player.setCurrentRoom(pNewRoom);;
		}
		else
		{
			const char* strDirection = NULL;
			switch (selectedOption)
			{
			case playerOptions::GoNorth:
			{
				strDirection = "North";
			}
				break;
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
			cout << "There is no room to the " << strDirection << endl << endl;
		}
	}
}

void Game::RunGame()
{
	InitializeRooms();
	WelcomePlayer();

	bool shouldEnd = false;
	while (shouldEnd == false)
	{
		GivePlayerOptions();
		string playerInput;
		GetPlayerInput(playerInput);

		playerOptions selectedOption = EvaluateInput(playerInput);
		shouldEnd = selectedOption == playerOptions::Quit;
	}
}