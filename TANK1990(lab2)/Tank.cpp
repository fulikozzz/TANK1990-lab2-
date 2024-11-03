#include "Tank.h"
#include <conio.h>
#include <stdio.h>

Tank::Tank() {
    this->pos.Set_PosX(0);
    this->pos.Set_PosY(0);
    this->direction = LEFT;
    this->speed = 1;
    this->armor = 1;
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i].Set_Pos(this->Get_Pos());
        this->bullets[i].Set_Direction(this->Get_Direction());
        this->bullets[i].Set_Speed(1);
        this->bullets[i].Set_IsActive(0);
        this->bullets[i].Set_BulletType(0);
    }
}
Tank::Tank(int x, int y, Direction dir, int speed, int armor, Bullet bullets[]) {
    this->pos.Set_PosX(x);
    this->pos.Set_PosY(y);
    this->direction = dir;
    this->speed = speed;
    this->armor = armor;
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        this->bullets[i] = bullets[i];
    }
}
Tank::~Tank() {

}

Position Tank::Get_Pos() { return this->pos; }
Direction Tank::Get_Direction() { return this->direction; }
int Tank::Get_Speed() { return this->speed; }
int Tank::Get_Armor() { return this->armor; }

void Tank::Set_Pos(Position position) {
    this->pos.Set_PosX(position.Get_PosX());
    this->pos.Set_PosY(position.Get_PosY());
}
void Tank::Set_Direction(Direction dir) { this->direction = dir; }
void Tank::Set_Speed(int speed) { this->speed = speed; }
void Tank::Set_Armor(int armor) { this->armor = armor; }

bool Tank::Check_Border() {
    Position pos = this->Get_Pos();
    Direction direction = this->Get_Direction();
    if (direction == UP && pos.Get_PosY() - this->Get_Speed() < 0 ||
        direction == RIGHT && pos.Get_PosX() + this->Get_Speed() >= 20 ||
        direction == DOWN && pos.Get_PosY() + this->Get_Speed() >= 20 ||
        direction == LEFT && pos.Get_PosX() - this->Get_Speed() < 0) {
        this->pos.Set_PosX(pos.Get_PosX());
        this->pos.Set_PosY(pos.Get_PosY());
        printf("Танк уперся в границу! Его текущая позиция (%d;%d)\n", this->pos.Get_PosX(), this->pos.Get_PosY());
        return true;
    }
    return false;
}
void Tank::Control(){
    if (_kbhit()) {
        char key = _getch();  // Получить символ ввода
        switch (key) {
        case 'W': case 'w':
            this->Set_Direction(UP);
            if (!this->Check_Border()) this->pos.Set_PosY(this->pos.Get_PosY() - this->Get_Speed());
            break;
        case 'D': case 'd':
            this->Set_Direction(RIGHT);
            if (!this->Check_Border()) this->pos.Set_PosX(this->pos.Get_PosX() + this->Get_Speed());
            break;
        case 'S': case 's':
            this->Set_Direction(DOWN);
            if (!this->Check_Border()) this->pos.Set_PosY(this->pos.Get_PosY() + this->Get_Speed());
            break;
        case 'A': case 'a':
            this->Set_Direction(LEFT);
            if (!this->Check_Border()) this->pos.Set_PosX(this->pos.Get_PosX() - this->Get_Speed());
            break;
        case 'F': case 'f': Shoot(); break;
        }
        printf("Координаты танка: (%d;%d), Направление: %d \n", this->pos.Get_PosX(), this->pos.Get_PosY(), this->Get_Direction());

    }
}
void Tank::Shoot(){
    for (int i = 0; i < MAX_BULLETS_ON_SCREEN; i++) {
        if (this->bullets[i].Get_IsActive() == 0) {
            this->bullets[i].Set_Pos(this->pos);
            this->bullets[i].Set_Direction(direction);
            this->bullets[i].Set_IsActive(true);
            this->bullets[i].Move();
            return; 
        }
    }
}