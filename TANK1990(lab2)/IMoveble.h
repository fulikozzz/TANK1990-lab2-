#pragma once
#include "Position.h"
#include "Direction.h"
#include <iostream>

class IMoveble
{
public:
	virtual ~IMoveble() = default;
	virtual void Move(Position& pos, Direction dir, int speed) = 0;
};

