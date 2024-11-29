#include "Bullet.h"

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

Bullet::Bullet(const Bullet& other) {
	this->pos = other.pos;
	this->direction = other.direction;
	this->speed = other.speed;
	this->isActive = other.isActive;
	this->bulletType = other.bulletType;
}

Bullet::~Bullet() {

}

Position Bullet::Get_Pos() { return pos; }

Direction Bullet::Get_Direction() { return direction; }

int Bullet::Get_Speed() { return speed; }

bool Bullet::Get_IsActive() { return isActive; }

int Bullet::Get_BulletType() { return bulletType; }

void Bullet::Set_Pos(Position position) {
	pos.Set_PosX(position.Get_PosX());
	pos.Set_PosY(position.Get_PosY());
}

void Bullet::Set_Direction(Direction dir) { direction = dir; }

void Bullet::Set_Speed(int speed) { this->speed = speed; }

void Bullet::Set_IsActive(bool isActive) { this->isActive = isActive; }

void Bullet::Set_BulletType(int bulletType) { this->bulletType = bulletType; }

bool Bullet::Check_Border() {
	if (pos.Get_PosX() < 0 || pos.Get_PosY() < 0 || pos.Get_PosX() >= 20 || pos.Get_PosY() >= 20) return true;
	return false;
}

void Bullet::Move() {
	if (!isActive) return; 

	switch (direction) {
	case LEFT:
		pos.Set_PosX(pos.Get_PosX() - speed);
		break;
	case RIGHT:
		pos.Set_PosX(pos.Get_PosX() + speed);
		break;
	case UP:
		pos.Set_PosY(pos.Get_PosY() - speed);
		break;
	case DOWN:
		pos.Set_PosY(pos.Get_PosY() + speed);
		break;
	default:
		break;
	}
	
	if (Check_Border()) {
		isActive = false;
	}
}
