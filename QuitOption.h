#pragma once
#include "Option.h"
class QuitOption :
	public Option
{

private:
	bool m_shouldQuit;

public:
	QuitOption();
	QuitOption(const std::string& outputText);
	~QuitOption();

	bool ShouldQuit() const { return m_shouldQuit; }
	bool Evaluate(const std::string& optionText, PlayerClass& player);
};



