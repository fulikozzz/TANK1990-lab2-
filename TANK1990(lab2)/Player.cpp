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

int Player::Get_Lives() { return lives; }

int Player::Get_Score() { return score; }

//void Player::Set_Tank(Tank tank) { this->tank = tank; }

void Player::Set_Lives(int lives) { this->lives = lives; }

void Player::Set_Score(int score) { this->score = score; }

void Player::Move() {
    Direction dir = Get_Direction();
    switch (dir) {
    case UP:
        if (!Check_Border()) pos.Set_PosY(pos.Get_PosY() - Get_Speed());
        break;
    case RIGHT:
        if (!Check_Border()) pos.Set_PosX(pos.Get_PosX() + Get_Speed());
        break;
    case DOWN:
        if (!Check_Border()) pos.Set_PosY(pos.Get_PosY() + Get_Speed());
        break;
    case LEFT:
        if (!Check_Border()) pos.Set_PosX(pos.Get_PosX() - Get_Speed());
        break;
    }
}

void Player::Shoot() {
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (bullets[i].Get_IsActive() == false) {
            bullets[i].Set_Pos(std::make_shared<Position>(pos));
            bullets[i].Set_Direction(direction);
            bullets[i].Set_IsActive(true);
            bullets[i].Move();
            return;
        }
    }
}

bool Player::Control() {
    if (_kbhit()) {
        char key = _getch();  
        switch (key) {
        case 'W': case 'w':
            Set_Direction(UP);
            Move();
            break;
        case 'D': case 'd':
            Set_Direction(RIGHT);
            Move();
            break;
        case 'S': case 's':
            Set_Direction(DOWN);
            Move();
            break;
        case 'A': case 'a':
            Set_Direction(LEFT);
            Move();
            break;
        case 'F': case 'f': Shoot();
            break;
        }
        return true;
    }
    return false;
}