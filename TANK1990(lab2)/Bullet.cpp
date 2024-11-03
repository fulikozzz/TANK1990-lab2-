#include "Bullet.h"

#include <stdio.h>

Bullet::Bullet() {
	this->pos.Set_PosX(0);
	this->pos.Set_PosY(0);
	this->direction = RIGHT;
	this->speed = 0;
	this->isActive = false;
	this->bulletType = 0;
}

Bullet::Bullet(int x, int y, Direction dir, int speed, bool isActive, int bulletType) {
	this->pos.Set_PosX(x);
	this->pos.Set_PosY(y);
	this->direction = dir;
	this->speed = speed;
	this->isActive = isActive;
	this->bulletType = bulletType;
}

Bullet::~Bullet() {

}

Position Bullet::Get_Pos() { return this->pos; }

Direction Bullet::Get_Direction() { return this->direction; }

int Bullet::Get_Speed() { return this->speed; }

bool Bullet::Get_IsActive() { return this->isActive; }

int Bullet::Get_BulletType() { return this->bulletType; }

void Bullet::Set_Pos(Position position) {
	this->pos.Set_PosX(position.Get_PosX());
	this->pos.Set_PosY(position.Get_PosY());
}

void Bullet::Set_Direction(Direction dir) {

	this->direction = dir;
}

void Bullet::Set_Speed(int speed) {
	this->speed = speed;
}

void Bullet::Set_IsActive(bool isActive) {
	this->isActive = isActive;
}

void Bullet::Set_BulletType(int bulletType) {
	this->bulletType = bulletType;
}

bool Bullet::Check_Border() {
	if (this->pos.Get_PosX() < 0 || this->pos.Get_PosY() < 0 || this->pos.Get_PosX() >= 20 || this->pos.Get_PosY() >= 20) return true;
	return false;
}

void Bullet::Move() {
	while (this->isActive == true) {
		switch (this->direction)
		{
		case LEFT: this->pos.Set_PosX(this->pos.Get_PosX() - this->speed);
			break;
		case RIGHT: this->pos.Set_PosX(this->pos.Get_PosX() + this->speed);
			break;
		case UP: this->pos.Set_PosY(this->pos.Get_PosY() - this->speed);
			break;
		case DOWN:this->pos.Set_PosY(this->pos.Get_PosY() + this->speed);
			break;
		default:
			break;
		}
		if (this->Check_Border() == true) this->isActive = 0;
		//printf("Координаты снаряда (%d, %d) в направлении %d\n", this->pos.Get_PosX(), this->pos.Get_PosY(), this->Get_Direction());
	}
}
