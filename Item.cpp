#include "stdafx.h"
#include "Item.h"


Item::Item(const std::string& name)
	:m_name(name)
{
}




const std::string& Item::GetName()const
{
	return m_name;
}