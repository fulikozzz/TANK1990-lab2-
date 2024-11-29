#include "Wall.h"

Wall::Wall() {
	this->pos.Set_PosX(0);
	this->pos.Set_PosY(0);
	this->type = EMPTY;
}

Wall::Wall(int x, int y, Type type) {
	this->pos.Set_PosX(x);
	this->pos.Set_PosY(y);
	this->type = type;
}

Wall::Wall(const Wall& other) {
	this->pos = other.pos;
	this->type = other.type;
}

Wall::~Wall() {

}

Position Wall::Get_Pos() { return this->pos; }

Type Wall::Get_Type() { return this->type; }

void Wall::Set_Pos(Position pos) { this->pos = pos; }

void Wall::Set_Type(Type type) { this->type = type; }