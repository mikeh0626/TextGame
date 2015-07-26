#include "stdafx.h"
#include "Option.h"

Option::Option()
{
}

Option::Option(playerOptions t, const std::string& outputText)
	:p_choose(t),
	m_outPutText(outputText)
{
}


Option::~Option()
{
}

//set option text from chosen option
void Option::SetOptionTxt(const std::string& optionText)
{
	m_optionText = optionText;
}


//returns output from text chosen
const std::string& Option::GetOutputText() const
{
	return m_outPutText;
}

//gets the chosen option
playerOptions Option::GetChosenOption() const
{
	return p_choose;
}