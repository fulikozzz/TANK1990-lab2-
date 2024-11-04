#include "Enemy.h"

Enemy::Enemy() {
	Tank tank;
	int armor = 1;
	this->tank = tank;
	this->armor = armor;
}

Enemy::Enemy(Tank tank, int armor) {
	this->tank = tank;
	this->armor = armor;
}

Enemy::~Enemy() {

}

Tank& Enemy::Get_Tank() { return this->tank; }
int Enemy::Get_Armor() { return this->armor; }

void Enemy::Set_Tank(Tank tank) { this->tank = tank; }
void Enemy::Set_Armor(int armor) { this->armor = armor; }

void Enemy::Move() {
	
}

void Enemy::Shoot() {

}