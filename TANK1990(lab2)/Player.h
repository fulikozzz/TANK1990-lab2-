#pragma once
#include "Tank.h"
//#include "IMoveble.h"
//#include "MoveWithKeyboard.h"

class Player : public Tank
{
private:
	//Tank tank;
	//IMoveble* behaviour;
	int lives;
	int score;

public:
	Player();
	Player(/*IMoveble* behaviour, */Position pos, int speed, Direction dir, int lives, int score);
	Player(const Player& other);
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
	Player* CloneShallow() const;
	Player* CloneDeep() const;

	void Print_Info();
};

