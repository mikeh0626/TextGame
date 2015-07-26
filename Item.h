#pragma once
#include <iostream>
class Item
{
private:
	std::string m_name;
public:
	Item(const std::string& name);
	virtual ~Item(){}

	const std::string& GetName()const;
};

