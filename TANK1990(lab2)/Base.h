#pragma once
#include "Position.h"
class Base
{
private:
	Position pos;
	bool is_destroyed;
public:
	Base();
	Base(int x, int y, bool is_destroyed);
	~Base();
	Position Get_Pos();
	bool Get_Is_Destroyed();
	void Set_Pos(Position pos);
	void Set_Is_Destroyed(bool is_destroyed);

};

