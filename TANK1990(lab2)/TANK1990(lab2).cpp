#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

// Танк игрока
struct PlayerTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
    int life_count;
    int isActive;
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

// Функция для движения танка
void moveTank(struct PlayerTank* tank) {
    if (tank->isActive) {
        switch (tank->vector) {
        case 0: tank->pos_y -= tank->speed; break; // Вверх
        case 1: tank->pos_x += tank->speed; break; // Вправо
        case 2: tank->pos_y += tank->speed; break; // Вниз
        case 3: tank->pos_x -= tank->speed; break; // Влево
        }
        printf("Танк игрока перемещен на позицию (%d, %d)\n", tank->pos_x, tank->pos_y);

        // Проверка выхода за границы поля
        if (tank->pos_x >= 100) {
            tank->pos_x = 99; // Откат вправо
            printf("Танк вышел за правую границу и возвращен на позицию (%d, %d)\n", tank->pos_x, tank->pos_y);
        }
        if (tank->pos_x <= 0) {
            tank->pos_x = 1; // Откат влевоz
            printf("Танк вышел за левую границу и возвращен на позицию (%d, %d)\n", tank->pos_x, tank->pos_y);
        }
        if (tank->pos_y >= 100) {
            tank->pos_y = 99; // Откат вниз
            printf("Танк вышел за нижнюю границу и возвращен на позицию (%d, %d)\n", tank->pos_y, tank->pos_x);
        }
        if (tank->pos_y <= 0) {
            tank->pos_y = 1; // Откат вверх
            printf("Танк вышел за верхнюю границу и возвращен на позицию (%d, %d)\n", tank->pos_y, tank->pos_x);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    struct PlayField field;
    struct PlayerTank player;
    struct EnemyTank enemy;
    struct Bullet bullet;
    // Инициализация обьектов
    initPlayField(&field, 100, 100);
    
    char key;
    int start = 1;

    while (start) {
        // Проверка ввода пользователя
        if (_kbhit()) {
            key = _getch();  // Получить символ ввода

            switch (key) {
            case 'W': case 'w': player.vector = 0; moveTank(&player); break; // Вверх
            case 'D': case 'd': player.vector = 1; moveTank(&player); break; // Вправо
            case 'S': case 's': player.vector = 2; moveTank(&player); break; // Вниз
            case 'A': case 'a': player.vector = 3; moveTank(&player); break; // Влево
            case 'Q': case 'q': start = 0; break;                            // Выйти
            }

        }


    // Освобождение ресурсов
    freePlayField(&field);
    return 0;
}
