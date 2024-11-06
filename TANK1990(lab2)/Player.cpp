#include "Player.h"
#include "Position.h"

#include <conio.h>

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

void Player::Control() {
    if (_kbhit()) {
        char key = _getch();  
        switch (key) {
        case 'W': case 'w':
            this->tank.Set_Direction(UP);
            this->Get_Tank().Move();
            break;
        case 'D': case 'd':
            this->tank.Set_Direction(RIGHT);
            this->Get_Tank().Move(); 
            break;
        case 'S': case 's':
            this->tank.Set_Direction(DOWN);
            this->Get_Tank().Move();
            break;
        case 'A': case 'a':
            this->tank.Set_Direction(LEFT);
            this->Get_Tank().Move();
            break;
        case 'F': case 'f': this->tank.Shoot();
            break;
        }
    }
}