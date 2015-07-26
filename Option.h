#pragma once

#include "PlayerClass.h"
#include "playerOptions.h"

class PlayerClass;
class Option
{

protected:
	playerOptions p_choose;
	std::string m_outPutText;
	//variable to hold user option choice
	std::string m_optionText;


public:
	Option();
	Option(playerOptions t, const std::string& outputText);
	~Option();

	void SetOptionTxt(const std::string& optionText);
	const std::string& GetOutputText() const;
	playerOptions GetChosenOption() const;

	
	//pure virtual method extended classes needs to implement own version
	 virtual bool Evaluate(const std::string& optionText, PlayerClass& player)=0;
	//void Evaluates(PlayerClass& player);
};

