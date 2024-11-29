#include "Enemy.h"

Enemy::Enemy() {
	this->Set_Pos(Position(5, 5));
	this->Set_Speed(1);
	this->Set_Direction(UP);
	this->armor = 1;
}

Enemy::Enemy(Position pos, int speed, Direction dir, int armor) {
	this->Set_Pos(pos);
	this->Set_Speed(speed);
	this->Set_Direction(dir);
	this->armor = armor;
}

Enemy::Enemy(const Enemy& other) {
	this->pos = other.pos;
	this->speed = other.speed;
	this->direction = other.direction;
	this->armor = other.armor;
}

Enemy::~Enemy() {

}

/*Tank& Enemy::Get_Tank() { return this->tank; }*/

int Enemy::Get_Armor() { return this->armor; }

/*void Enemy::Set_Tank(Tank tank) { this->tank = tank; }*/

void Enemy::Set_Armor(int armor) { this->armor = armor; }

void Enemy::Move() {
	/* Здесь будет реализация логики движения противника */
}

void Enemy::Shoot() {
	/* Здесь будет реализация логики стрельбы противника */
}