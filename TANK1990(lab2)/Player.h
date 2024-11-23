#pragma once
#include "Tank.h"

class Player : public Tank
{
private:
	//Tank tank;
	int lives;
	int score;

public:
	Player();
	Player(Position pos, int speed, Direction dir, int lives, int score);
	~Player();

	//Tank& Get_Tank();
	int Get_Lives();
	int Get_Score();
	
	//void Set_Tank(Tank tank);
	void Set_Lives(int lives);
	void Set_Score(int score);
	bool Control();
	void Move() override;
	void Shoot() override;
};

