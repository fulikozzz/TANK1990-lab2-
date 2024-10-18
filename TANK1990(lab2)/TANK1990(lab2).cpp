#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

// Позиция
struct Position {
    int pos_x;
    int pos_y;
};

// Снаряд
struct Bullet {
    struct Position pos;
    int direction;
    int speed;
    int isActive;
    int bulletType;
};

// Танк
struct Tank {
    struct Position pos;
    int direction;
    int speed;
    struct Bullet bullets[5];
};

// Игрок
struct Player{
    struct Tank tank;
    int lives;
    int score;
};

// Противник
struct Enemy {
    struct Tank tank;
};

// Бонус
struct Bonus {
    struct Position pos;
    int type;
    int isActive;
};

// Стены
struct Wall {
    struct Position pos;
    int type;
};

// База игрока
/*struct Base {
    struct Position pos;
    int isDestroyed;
};*/

// Игровое поле
struct Map {
    struct Wall walls[20][20];
    //struct Base base;
    struct Bonus bonuses[4];
};

// Игра
struct Game {
    int level;
    struct Map map;
    struct Player player;
    int gameOver;
};

                    /* ИНИЦИАЛИЗАЦИЯ */
// Инициализация позиции
void initPosition(struct Position* pos) {
    pos->pos_x = 0;
    pos->pos_y = 0;
}

// Инициализация игрового поля
void initMap(struct Map* map) {
    // Инициализация стен
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            map->walls[i][j].pos.pos_x = i;  // Позиция стены по X
            map->walls[i][j].pos.pos_y = j;  // Позиция стены по Y
            map->walls[i][j].type = 1;            // Тип стены (например, обычная стена)
        }
    }
    // Инициализация бонусов
    for (int i = 0; i < 4; i++) {
        map->bonuses[i].pos.pos_x = rand() % 20;  // Рандомная позиция по X
        map->bonuses[i].pos.pos_y = rand() % 20;  // Рандомная позиция по Y
        map->bonuses[i].type = rand() % 2;         // Тип бонуса (например, улучшение)
        map->bonuses[i].isActive = 1;              // Бонус активен
    }
    printf("Игровое поле проинициализировано с размерами 20 * 20\n");
}

// Инициализацмя игрока
void initPlayer(struct Player* player) {
    player->lives = 3;  
    player->score = 0;   
    player->tank.pos.pos_x = 0;  
    player->tank.pos.pos_y = 10;  
    player->tank.direction = 0;     
    player->tank.speed = 1;     
    // Инициализация снаярдов
    for (int i = 0; i < 5; i++) {  
        player->tank.bullets[i].isActive = 0;  
        player->tank.bullets[i].speed = 0;
        player->tank.bullets[i].bulletType = 0; 
    }
}

// Инициализацмя противника
void initEnemy(struct Enemy* enemy) {
    enemy->tank.pos.pos_x = 20;  
    enemy->tank.pos.pos_y = 10; 
    enemy->tank.direction = 0;     
    enemy->tank.speed = 1;       
    // Инициализация cнарядов
    for (int i = 0; i < 5; i++) { 
        enemy->tank.bullets[i].isActive = 0;
        enemy->tank.bullets[i].speed = 0;
        enemy->tank.bullets[i].bulletType = 0;
    }
}

// Инициадихация игры
void initGame(struct Game* game) {
    game->level = 1;
    game->gameOver = 0;
    initMap(&game->map);  // Инициализация карты
    initPlayer(&game->player);  // Инициализация игрока
}
/*
// Функция для стрельбы
void shootBullet(struct Bullet* bullet, struct PlayerTank* tank) {
    if (!bullet->isActive) {
        bullet->pos_x = tank->pos_x;
        bullet->pos_y = tank->pos_y;
        bullet->vector = tank->vector;
        bullet->speed = 1;
        bullet->isActive = 1;
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
            bullet->isActive = 0;
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
}*/

// Функция для движения танка
void moveTankPlayer(struct Player& PlayerTank) {
    if (_kbhit()) {
        char key = _getch();  // Получить символ ввода

        switch (key) {
        case 'W': case 'w': PlayerTank.tank.direction = 0; PlayerTank.tank.pos.pos_y -= PlayerTank.tank.speed; break;
        case 'D': case 'd': PlayerTank.tank.direction = 1; PlayerTank.tank.pos.pos_x += PlayerTank.tank.speed; break;
        case 'S': case 's': PlayerTank.tank.direction = 2; PlayerTank.tank.pos.pos_y += PlayerTank.tank.speed; break;
        case 'A': case 'a': PlayerTank.tank.direction = 3; PlayerTank.tank.pos.pos_x -= PlayerTank.tank.speed; break;
            //case 'F': case 'f': shootBullet(&bullet, &player); break;        // Стрелять
            //case 'Q': case 'q': start = false; break;                        // Выйти
        }
        printf("tank coords %d %d\n", PlayerTank.tank.pos.pos_x, PlayerTank.tank.pos.pos_y);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    Game game;

    // Инициализация игры
    initGame(&game);

    // Основной игровой цикл
    int start = 1;
    while (start && !game.gameOver) {
        moveTankPlayer(game.player);
    }
    return 0;
}