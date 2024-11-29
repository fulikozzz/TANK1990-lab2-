#include "Tank.h"
#include <conio.h>

Tank::Tank() {
    printf("Вызван конструктор базового класса\n");
    this->pos.Set_PosX(1);
    this->pos.Set_PosY(1);
    this->direction = LEFT;
    this->speed = 1;
    this->armor = 1;
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i].Set_Pos(this->Get_Pos());
        this->bullets[i].Set_Direction(this->Get_Direction());
        this->bullets[i].Set_Speed(1);
        this->bullets[i].Set_IsActive(0);
        this->bullets[i].Set_BulletType(0);
    }
}

Tank::Tank(Position pos, Direction dir, int speed, int armor) {
    this->pos = pos;
    this->direction = dir;
    this->speed = speed;
    this->armor = armor;
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i].Set_Pos(this->Get_Pos());
        this->bullets[i].Set_Direction(this->Get_Direction());
        this->bullets[i].Set_Speed(1);
        this->bullets[i].Set_IsActive(0);
        this->bullets[i].Set_BulletType(0);
    }
}

Tank::Tank(const Tank& other) {
    this->pos = other.pos;
    this->direction = other.direction;
    this->speed = other.speed;
    this->armor = other.armor;
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i] = other.bullets[i];
    }
}

Tank::~Tank() {
    this->bullets.clear();
}

Position Tank::Get_Pos() { return this->pos; }

Direction Tank::Get_Direction() { return this->direction; }

int Tank::Get_Speed() { return this->speed; }

int Tank::Get_Armor() { return this->armor; }

std::vector<Bullet>& Tank::Get_Bullets() { return this->bullets; }

void Tank::Set_Pos(Position position) {
    this->pos.Set_PosX(position.Get_PosX());
    this->pos.Set_PosY(position.Get_PosY());
}

void Tank::Set_Direction(Direction dir) { this->direction = dir; }

void Tank::Set_Speed(int speed) { this->speed = speed; }

void Tank::Set_Armor(int armor) { this->armor = armor; }

void Tank::Set_Bullet(int index, const Bullet& bullet) {
    if (index >= 0 && index < MAX_BULLETS_ON_SCREEN) this->bullets[index] = bullet;
}

bool Tank::Check_Border() {
    Position pos = this->Get_Pos();
    Direction direction = this->Get_Direction();
    if (direction == UP && pos.Get_PosY() - this->Get_Speed() < 0 ||
        direction == RIGHT && pos.Get_PosX() + this->Get_Speed() > 20 ||
        direction == DOWN && pos.Get_PosY() + this->Get_Speed() > 20 ||
        direction == LEFT && pos.Get_PosX() - this->Get_Speed() < 0) {
        this->pos.Set_PosX(pos.Get_PosX());
        this->pos.Set_PosY(pos.Get_PosY());
        return true;
    }
    return false;
}

void Tank::Move(){
    Direction dir = this->Get_Direction();
        switch (dir) {
        case UP:
            if (!this->Check_Border()) this->pos.Set_PosY(this->pos.Get_PosY() - this->Get_Speed());
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

void Tank::Shoot(){
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