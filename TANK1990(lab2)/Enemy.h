#pragma once
#include "Tank.h"

class Enemy : public Tank
{
private:
	//Tank tank;
	int armor;

public:
	Enemy();
	Enemy(Position pos, int speed, Direction dir, int armor);
	Enemy(const Enemy& other);
	~Enemy();

	//Tank& Get_Tank();
	int Get_Armor();
	
	//void Set_Tank(Tank tank);
	void Set_Armor(int armor);
	
	void Move() override;
	void Shoot() override;
};

