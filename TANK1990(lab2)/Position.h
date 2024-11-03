#pragma once

class Position
{
private:
	int pos_x;
	int pos_y;

public: 
	Position();
	Position(int valueX, int valueY);
	~Position();
	
	int Get_PosX();
	int Get_PosY();
	
	void Set_PosX(int valueX);
	void Set_PosY(int valueY);
};

