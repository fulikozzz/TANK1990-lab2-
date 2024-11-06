#pragma once
#include "Position.h"

enum Type {EMPTY, IRON, BRIC_FULL, BRICK_HALF, BRICK_LOW, WOOD, ICE, BUSH, WATER, PLAYER, ENEMY};

class Wall
{
private:
	Position pos;
	Type type;

public:
	Wall();
	Wall(int x, int y, Type type);
	~Wall();

	Position Get_Pos();
	Type Get_Type();
	void Set_Pos(Position pos);
	void Set_Type(Type type);
};

