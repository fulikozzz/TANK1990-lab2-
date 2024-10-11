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
// Функция для стрельбы
void shootBullet(struct Bullet* bullet, struct PlayerTank* tank) {
    if (!bullet->isActive) {
        bullet->pos_x = tank->pos_x;
        bullet->pos_y = tank->pos_y;
        bullet->vector = tank->vector;
        bullet->speed = 1;
        bullet->isActive = true;
        printf("Снаряд выпущен с позиции (%d, %d)\n", bullet->pos_x, bullet->pos_y);
    }
}

// Функция для перемещения пули
void moveBullet(struct Bullet* bullet) {
    if (bullet->isActive) {
        switch (bullet->vector) {
        case 0: bullet->pos_y -= bullet->speed; break; 
        case 1: bullet->pos_x += bullet->speed; break; 
        case 2: bullet->pos_y += bullet->speed; break; 
        case 3: bullet->pos_x -= bullet->speed; break; 
        }
        printf("Координаты снаряда (%d, %d)\n", bullet->pos_x, bullet->pos_y);

       
    }
}


int main()
{

}
