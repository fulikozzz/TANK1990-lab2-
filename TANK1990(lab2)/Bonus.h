#pragma once
#include "Position.h"
enum Type {LIFE, BULLET, TIME, INVULNERABILITY};
class Bonus
{
private:
		Position pos;
		Type type;
		int activity_time;

public:
	Bonus();
	Bonus(int x, int y, Type type, int activity_time);
	~Bonus();

	Position Get_Pos();
	Type Get_Type();
	int Get_Activity_Time();

	void Set_Pos(Position position);
	void Set_Type(Type type);
	void Set_Activity_Time(int time);

		
};

