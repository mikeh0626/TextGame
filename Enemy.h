#pragma once
#include "Entity.h"
class Enemy :
	public Entity
{
public:

	enum class EnemyType
	{
		Dragon,
		Orc
	};
	Enemy();
private:
	
	EnemyType m_type;
	bool m_alive{ true };

public:
	Enemy(EnemyType type);

	bool isAlive() const;
	void Kill();
	~Enemy();
};

