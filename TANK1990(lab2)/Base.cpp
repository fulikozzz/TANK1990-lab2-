#include "Base.h"

Base::Base() {

	this->pos.Set_PosX(1);
	this->pos.Set_PosY(1);
	this->is_destroyed = false;
}

Base::Base(const Base& other) {
	this->pos = other.pos;
	this->is_destroyed = other.is_destroyed;
}

Base::Base(int x, int y, bool is_destroyed) {
	this->pos.Set_PosX(x);
	this->pos.Set_PosY(y);
	this->is_destroyed = is_destroyed;
}

Base::~Base() {

}

Position Base::Get_Pos() { return pos; }

bool Base::Get_Is_Destroyed() { return is_destroyed; }

void Base::Set_Pos(Position position) {
	pos.Set_PosX(position.Get_PosX());
	pos.Set_PosY(position.Get_PosY());
}

void Base::Set_Is_Destroyed(bool is_destroyed) { this->is_destroyed = is_destroyed; }