#include "Player.h"
#include "Position.h"

#include <conio.h>
#include <iostream>

Player::Player() {
    printf("Вызван конструктор производного класса\n");
    Tank(); // вызов конструктора базового класса
    /* Инициализируется конструктором
    this->Set_Pos(Position(0, 0));
    this->Set_Speed(1);
    this->Set_Direction(UP);
    */
	this->lives = 3;
	this->score = 0;
}

Player::Player(Position pos, int speed, Direction dir, int lives, int score) {
	this->Set_Pos(pos);
    this->Set_Speed(speed);
    this->Set_Direction(dir);
	this->lives = lives;
	this->score = score;
}

Player::Player(const Player& other) {
    this->pos = other.pos;
    this->speed = other.speed;
    this->direction = other.direction;
    this->armor = other.armor;
    this->lives = other.lives;
    this-> score= other.score;
}

Player::~Player() { 

}

//Tank& Player::Get_Tank() { return this->tank; }

int Player::Get_Lives() { return this->lives; }

int Player::Get_Score() { return this->score; }

//void Player::Set_Tank(Tank tank) { this->tank = tank; }

void Player::Set_Lives(int lives) { this->lives = lives; }

void Player::Set_Score(int score) { this->score = score; }

void Player::Move() {
    Direction dir = this->Get_Direction();
    switch (dir) {
    case UP:
        if (!Check_Border()) this->pos.Set_PosY(this->pos.Get_PosY() - this->Get_Speed());
        break;
    case RIGHT:
        if (!this->Check_Border()) this->pos.Set_PosX(this->pos.Get_PosX() + this->Get_Speed());
        break;
    case DOWN:
        if (!this->Check_Border()) this->pos.Set_PosY(this->pos.Get_PosY() + this->Get_Speed());
        break;
    case LEFT:
        if (!this->Check_Border()) this->pos.Set_PosX(this->pos.Get_PosX() - this->Get_Speed());
        break;
    }
}

void Player::Shoot() {
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (this->bullets[i].Get_IsActive() == false) {
            this->bullets[i].Set_Pos(this->pos);
            this->bullets[i].Set_Direction(direction);
            this->bullets[i].Set_IsActive(true);
            this->bullets[i].Move();
            return;
        }
    }
}

bool Player::Control() {
    if (_kbhit()) {
        char key = _getch();  
        switch (key) {
        case 'W': case 'w':
            this->Set_Direction(UP);
            this->Move();
            break;
        case 'D': case 'd':
            this->Set_Direction(RIGHT);
            this->Move();
            break;
        case 'S': case 's':
            this->Set_Direction(DOWN);
            this->Move();
            break;
        case 'A': case 'a':
            this->Set_Direction(LEFT);
            this->Move();
            break;
        case 'F': case 'f': this->Shoot();
            break;
        }
        return true;
    }
    return false;
}