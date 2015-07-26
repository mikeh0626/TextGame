#include "stdafx.h"
#include "Chest.h"


Chest::Chest()
{

}

Chest::Chest(const Item* item)
	:m_item{item}
{
}


Chest::~Chest()
{
}

bool Chest::IsOpen()const
{
	return m_isOpen;
}
const Item* Chest::Open()
{
	m_isOpen = true;
	return m_item;
}
