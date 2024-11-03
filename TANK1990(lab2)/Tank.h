#pragma once
#include "Position.h"
#include "Bullet.h"

#define MAX_BULLETS_ON_SCREEN 3

class Tank
{
private:
    Position pos;
    Direction direction;
    int speed;
    int armor;
    Bullet bullets[MAX_BULLETS_ON_SCREEN];

public:
    Tank();
    Tank(int x, int y, Direction direction, int speed, int armor, Bullet bullets[]);
    ~Tank();
    
    Position Get_Pos();
    Direction Get_Direction();
    int Get_Speed();
    int Get_Armor();
    //int Get_Bullets();

    void Set_Pos(Position position);
    void Set_Direction(Direction dir);
    void Set_Speed(int speed);
    void Set_Armor(int armor);
    //void Set_Bullets();

    //Setting
    bool Check_Border();
    void Control();
    void Shoot();
};

