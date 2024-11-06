#pragma once
#include "Position.h"

enum KindOf {LIFE, BULLET, TIME, INVULNERABILITY};

class Bonus
{
private:
		Position pos;
		KindOf kind;
		int activity_time;

public:
	Bonus();
	Bonus(int x, int y, KindOf kind, int activity_time);
	~Bonus();

	Position Get_Pos();
	KindOf Get_Kind();
	int Get_Activity_Time();

	void Set_Pos(Position position);
	void Set_Kind(KindOf kind);
	void Set_Activity_Time(int time);		
};

