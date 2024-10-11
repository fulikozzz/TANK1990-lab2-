#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Танк игрока
struct PlayerTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
    int life_count;
};

// Танк противника
struct EnemyTank {
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
    int isActive;
};

// Игровое поле
struct PlayField {
    int size_x;
    int size_y;
    int** grid;
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
        
        // Деактивировать пулю, если она вышла за пределы поля
        if (bullet->pos_x < 0 || bullet->pos_x > 100 || bullet->pos_y < 0 || bullet->pos_y > 100) {
            bullet->isActive = false;
            printf("Снаряд вышел за пределы поля и деактивирован\n");
        }
       
    }
}

// Функция попадания пули в танк противника
void BulletHit(struct Bullet* bullet, struct EnemyTank* enemyPlayer) {
    if (bullet->pos_x == enemyPlayer->pos_x && bullet->pos_y == enemyPlayer->pos_y) {
        enemyPlayer->life_count = 0;   // Уничтожение танка
        bullet->isActive = false;      // Деактивация пули
    }
}

// Инициализация игрового поля
void initPlayField(struct PlayField* field, int size_x, int size_y) {
    field->size_x = size_x;
    field->size_y = size_y;

    field->grid = (int**)malloc(size_x * sizeof(int*));
    field->grid = (int**)malloc(size_y * sizeof(int*));

    // Заполняем поле
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            field->grid[i][j] = 0;
        }
    }
    printf("Игровое поле проинициализировано с размерами %d x %d\n", size_x, size_y);
}

// Функция для очистки памяти игрового поля
void freePlayField(struct PlayField* field) {
    for (int i = 0; i < field->size_x; i++) {
        free(field->grid[i]);
    }
    free(field->grid);
    printf("Игровое поле удалено\n");
}

// Функция для инициализации игрока
void initPlayerTank(struct PlayerTank* tank) {
    tank->pos_x = 50;
    tank->pos_y = 50;
    tank->vector = 0;
    tank->life_count = 3;
    tank->speed = 1;
}

// Функция для инициализации врага
void initEnemyTank(struct EnemyTank* tank) {
    tank->pos_x = 50;
    tank->pos_y = 45;
    tank->vector = 0;
    tank->speed = 1;
    tank->life_count = 1; // Танк жив
}
int main()
{
    setlocale(LC_ALL, "Rus");
    struct PlayField field;
    struct PlayerTank player;
    struct EnemyTank enemy;
    // Инициализация обьектов
    initPlayField(&field, 100, 100);



    // Освобождение ресурсов
    freePlayField(&field);
    return 0;
}
