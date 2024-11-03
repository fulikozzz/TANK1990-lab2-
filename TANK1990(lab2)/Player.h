#pragma once
#include "Tank.h"

class Player
{
private:
	Tank tank;
	int lives;
	int score;
public:
	Player();
	Player(Tank tank, int lives, int score);
	~Player();

	Tank& Get_Tank();
	int Get_Lives();
	int Get_Score();
	
	void Set_Tank(Tank tank);
	void Set_Lives(int lives);
	void Set_Score(int score);

};

