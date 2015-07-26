#pragma once
#include "Entity.h"
#include "Item.h"
class Chest
	: public Entity
{

private:
	const Item* m_item;
	bool m_isOpen{ false };
public:
	Chest();
	Chest(const Item* item);
	~Chest();

	bool IsOpen()const;
	const Item* Open();
};

