#include <stdio.h>
#include <locale.h>

// Танк игрока
struct PlayerTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
    int life_count;
};

// Танк противника
struct PlayerTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
    int life_count;
};

// Снаряд
struct Bullet {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
    bool isActive;
};

// Игровое поле
struct PlayField {
    int size_x;
    int size_y;
};

int main()
{

}
