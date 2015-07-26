#include "stdafx.h"
#include "QuitOption.h"

QuitOption::QuitOption(const std::string& outputText)
	:Option(playerOptions::Quit, outputText),
	m_shouldQuit(false)
{
}


QuitOption::~QuitOption()
{
}

bool QuitOption::Evaluate(const std::string& optionText, PlayerClass& player)
{
	m_shouldQuit = m_optionText.compare(optionText) == 0;

	if (m_shouldQuit == true)
	{
		std::cout << "You have chosen to quit!" << std::endl << std::endl;
	}

	return m_shouldQuit;
}

