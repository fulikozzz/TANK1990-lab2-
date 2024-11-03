#include "Player.h"
#include "Position.h"

#include <stdio.h>

Player::Player() {
	Tank tank;
	this->tank = tank;
	this->lives = 3;
	this->score = 0;
	printf("Игровок проинициализирован на координатах (%d;%d) с направлением %d\n", this->tank.Get_Pos().Get_PosX(), this->tank.Get_Pos().Get_PosY(), this->tank.Get_Direction());
}
Player::Player(Tank tank, int lives, int score) {
	this->tank = tank;
	this->lives = lives;
	this->score = score;
}
Player::~Player() {  }

Tank& Player::Get_Tank() { return this->tank; }
int Player::Get_Lives() { return this->lives; }
int Player::Get_Score() { return this->score; }

void Player::Set_Tank(Tank tank) { this->tank = tank; }
void Player::Set_Lives(int lives) { this->lives = lives; }
void Player::Set_Score(int score) { this->score = score; }