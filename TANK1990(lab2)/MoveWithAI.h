#pragma once
#include "IMoveble.h"
#include <iostream>

class MoveWithAI : public IMoveble
{
public:
	void Move(Position& pos, Direction dir, int speed) override {
		switch (dir)
		{
		case LEFT:
			if (pos.Get_PosX() > 0)
			pos.Set_PosX(pos.Get_PosX() - 1);
			break;
		case RIGHT:
			if (pos.Get_PosX() < 19)
			pos.Set_PosX(pos.Get_PosX() + 1);
			break;
		case UP:
			if (pos.Get_PosY() > 0)
			pos.Set_PosY(pos.Get_PosY() - 1);
			break;
		case DOWN:
			if (pos.Get_PosX() > 19)
			pos.Set_PosY(pos.Get_PosY() + 1);
			break;
		default:
			break;
		}
		std::cout << "I'm moving with AI! " << std::endl;
	}
};

