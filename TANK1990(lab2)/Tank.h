#pragma once
#include "Position.h"
#include "Bullet.h"

#include <vector>

#define MAX_BULLETS_ON_SCREEN 2

class Tank
{
protected:
    Position pos;
    Direction direction;
    int speed;
    int armor;
    std::vector<Bullet> bullets;

public:
    Tank();
    Tank(Position pos, Direction direction, int speed, int armor);
    Tank(const Tank& other);
    virtual ~Tank();
    
    Position Get_Pos();
    Direction Get_Direction();
    int Get_Speed();
    int Get_Armor();
    std::vector<Bullet>& Get_Bullets();

    void Set_Pos(Position position);
    void Set_Direction(Direction dir);
    void Set_Speed(int speed);
    void Set_Armor(int armor);
    void Set_Bullet(int index, const Bullet& bullet);

    bool Check_Border();
    virtual void Move();
    virtual void Shoot();
};

