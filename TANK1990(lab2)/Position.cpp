#include "Position.h"

Position::Position() {
	this->pos_x = 0;
	this->pos_y = 0;
}
Position::Position(int valueX, int valueY) {
	this->pos_x = valueX;
	this->pos_y = valueY;
}

Position::~Position(){
}

void Position::Set_PosX(int valueX) {
	this->pos_x = valueX;
}
void Position::Set_PosY(int valueY) {
	this->pos_y = valueY;
}

int Position::Get_PosX() {
	int valueX;
	valueX = this->pos_x;
	return valueX;
}
int Position::Get_PosY() {
	int valueY;
	valueY = this->pos_y;
	return valueY;
}
