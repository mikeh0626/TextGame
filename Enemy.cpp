#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{

}
Enemy::Enemy(EnemyType type)
	:m_type{type}
{
}


Enemy::~Enemy()
{
}

bool Enemy::isAlive() const
{
	return m_alive;
}

void Enemy::Kill()
{
	m_alive = false;
}