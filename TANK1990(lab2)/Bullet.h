#pragma once
#include "Position.h"

#include "memory"

enum Direction { LEFT, RIGHT, UP, DOWN };

class Bullet
{
private:
	std::shared_ptr<Position> pos;
	Direction direction;
	int speed;
	bool isActive;
	int bulletType;

public:
	Bullet();
	Bullet(int x, int y, Direction dir, int speed, bool isActive, int bulletType);
	Bullet(const Bullet& other);
	~Bullet();

	std::shared_ptr<Position> Get_Pos();
	Direction Get_Direction();
	int Get_Speed();
	bool Get_IsActive();
	int Get_BulletType();

	void Set_Pos(std::shared_ptr<Position> position);
	void Set_Direction(Direction dir);
	void Set_Speed(int speed);
	void Set_IsActive(bool isActive);
	void Set_BulletType(int bulletType);

	bool Check_Border();
	void Move();
};

