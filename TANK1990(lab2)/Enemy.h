#pragma once
#include "Tank.h"

class Enemy
{
private:
	Tank tank;
	int armor;

public:
	Enemy();
	Enemy(Tank tank, int armor);
	~Enemy();
	Tank& Get_Tank();
	int Get_Armor();
	void Set_Tank(Tank tank);
	void Set_Armor(int armor);
	void Move();
	void Shoot();
};

