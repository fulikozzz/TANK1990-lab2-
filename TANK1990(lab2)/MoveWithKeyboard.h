#pragma once
#include "IMoveble.h"

class MoveWithKeyboard : public IMoveble
{
public: void Move(Position& pos, Direction dir, int speed) override {
	switch (dir)
	{
	case LEFT:
		pos.Set_PosX(pos.Get_PosX() - speed);
		break;
	case RIGHT:
		pos.Set_PosX(pos.Get_PosX() + speed);
		break;
	case UP:
		pos.Set_PosY(pos.Get_PosY() - speed);
		break;
	case DOWN:
		pos.Set_PosY(pos.Get_PosY() + speed);
		break;
	default:
		break;
	}
	std::cout << "I'm moving with keyboard! " << std::endl;
}
};

