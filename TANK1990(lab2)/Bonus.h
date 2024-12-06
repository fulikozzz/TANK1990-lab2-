#pragma once
#include "Position.h"
#include "iostream"

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
	Bonus(const Bonus& other) = delete;
	Bonus(const Bonus& other, int x);
	virtual ~Bonus();

	Position Get_Pos();
	KindOf Get_Kind();
	int Get_Activity_Time();

	void Set_Pos(Position position);
	void Set_Kind(KindOf kind);
	void Set_Activity_Time(int time);		

	// Перегрузка операторов
    //Bonus& operator=(Bonus other);
	//Bonus operator+(Bonus other);
	//Bonus operator-();
	//bool operator==(Bonus& other);
	/*std::ostream& operator<<(std::ostream& output) {
		output << "Bonus [Позиция: (" << pos.Get_PosX() << ", " << pos.Get_PosY()
			<< "), Вид: " << kind
			<< ", Время активности: " << activity_time << "]";
		return output;
	}*/
	friend std::ostream& operator<<(std::ostream& output, Bonus& bonus);

};

