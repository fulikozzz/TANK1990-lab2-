#include "Bonus.h"

Bonus::Bonus() {
	this->pos.Set_PosX(0);
	this->pos.Set_PosY(0);
	this->kind = LIFE;
	this->activity_time = 0;
}

Bonus::Bonus(int x, int y, KindOf kind, int activity_time) {
	this->pos.Set_PosX(x);
	this->pos.Set_PosY(y);
	this->kind = kind;
	this->activity_time = activity_time;

}

Bonus::~Bonus() {

}

Position Bonus::Get_Pos() { return this->pos; }

KindOf Bonus::Get_Kind() { return this->kind; }

int Bonus::Get_Activity_Time() { return this->activity_time; }

void Bonus::Set_Pos(Position position) {
	this->pos.Set_PosX(position.Get_PosX());
	this->pos.Set_PosY(position.Get_PosY());
}

void Bonus::Set_Kind(KindOf kind) { this->kind = kind; }

void Bonus::Set_Activity_Time(int activity_time) { this->activity_time = activity_time; }