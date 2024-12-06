#include "Tank.h"
#include <conio.h>

Tank::Tank() {
    printf("Вызван конструктор базового класса (БП)\n");
    this->pos.Set_PosX(1);
    this->pos.Set_PosY(1);
    this->direction = LEFT;
    this->speed = 1;
    this->armor = 1;
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i].Set_Pos(std::make_shared<Position>(this->Get_Pos()));
        this->bullets[i].Set_Direction(this->Get_Direction());
        this->bullets[i].Set_Speed(1);
        this->bullets[i].Set_IsActive(0);
        this->bullets[i].Set_BulletType(0);
    }
}

Tank::Tank(Position pos, Direction dir, int speed, int armor) {
    printf("Вызван конструктор базового класса (СП)\n");
    this->pos = pos;
    this->direction = dir;
    this->speed = speed;
    this->armor = armor;
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    this->bullets.resize(MAX_BULLETS_ON_SCREEN);
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i].Set_Pos(std::make_shared<Position>(this->Get_Pos()));
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

Position Tank::Get_Pos() { return pos; }

Direction Tank::Get_Direction() { return direction; }

int Tank::Get_Speed() { return speed; }

int Tank::Get_Armor() { return armor; }

std::vector<Bullet>& Tank::Get_Bullets() { return bullets; }

void Tank::Set_Pos(Position position) {
    pos.Set_PosX(position.Get_PosX());
    pos.Set_PosY(position.Get_PosY());
}

void Tank::Set_Direction(Direction dir) { direction = dir; }

void Tank::Set_Speed(int speed) { this->speed = speed; }

void Tank::Set_Armor(int armor) { this->armor = armor; }

void Tank::Set_Bullet(int index, const Bullet& bullet) {
    if (index >= 0 && index < MAX_BULLETS_ON_SCREEN) this->bullets[index] = bullet;
}

bool Tank::Check_Border() {
    Position pos = this->Get_Pos();
    Direction direction = this->Get_Direction();
    if (direction == UP && pos.Get_PosY() - Get_Speed() < 0 ||
        direction == RIGHT && pos.Get_PosX() + Get_Speed() >= 20 ||
        direction == DOWN && pos.Get_PosY() + Get_Speed() >= 20 ||
        direction == LEFT && pos.Get_PosX() - Get_Speed() < 0) {
        pos.Set_PosX(pos.Get_PosX());
        pos.Set_PosY(pos.Get_PosY());
        return true;
    }
    return false;
}

/*void Tank::Move() {
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

void Tank::Shoot(){
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (bullets[i].Get_IsActive() == false) {
            bullets[i].Set_Pos(std::make_shared<Position>(pos));
            bullets[i].Set_Direction(direction);
            bullets[i].Set_IsActive(true);
            bullets[i].Move();
            return; 
        }
    }
}*/