#pragma once
#include "Tank.h"

class Player : public Tank
{
private:
	int lives;
	int score;

public:
	Player();
	Player(Position pos, int speed, Direction dir, int lives, int score);
	Player(const Player& other);
	~Player();

	int Get_Lives();
	int Get_Score();
	
	void Set_Lives(int lives);
	void Set_Score(int score);
	bool Control();
	void Move() override;
	void Shoot() override;
	Player* CloneShallow() const;
	Player* CloneDeep() const;

	void Print_Info();
};

