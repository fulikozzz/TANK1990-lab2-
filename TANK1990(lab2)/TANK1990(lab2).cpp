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
    struct Enemy enemy;
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
// Иницицализация снаряда
void initBullet(struct Bullet* bullet) {
    bullet->isActive = 0;
    bullet->speed = 2;
    bullet->bulletType = 0;
}

// Инициализация игрока
void initPlayer(struct Player* player) {
    player->lives = 3;  
    player->score = 0;   
    player->tank.pos.pos_x = 1;  
    player->tank.pos.pos_y = 1;  
    player->tank.direction = 0;     
    player->tank.speed = 1;  
    for (int i = 0; i < 5; i++) initBullet(&player->tank.bullets[i]);
}

// Инициализацмя противника
void initEnemy(struct Enemy* enemy) {
    enemy->tank.pos.pos_x = 19;  
    enemy->tank.pos.pos_y = 19; 
    enemy->tank.direction = 0;     
    enemy->tank.speed = 1;       
    for (int i = 0; i < 5; i++) initBullet(&enemy->tank.bullets[i]);
}

// Инициадихация игры
void initGame(struct Game* game) {
    game->level = 1;
    game->gameOver = 0;
    initMap(&game->map);  // Инициализация карты
    initPlayer(&game->player);  // Инициализация игрока
    initEnemy(&game->enemy); // Инициализация противника
}

// Функция проверки границ для танка
int checkTankBorder(struct Tank* tank) {
    struct Position pos = tank->pos;
    int direction = tank->direction;
    if (direction == 0 && pos.pos_y - tank->speed < 0 ||
        direction == 1 && pos.pos_x + tank->speed >= 20 ||
        direction == 2 && pos.pos_y + tank->speed >= 20 ||
        direction == 3 && pos.pos_x - tank->speed < 0) {
        tank->pos.pos_x = pos.pos_x;
        tank->pos.pos_y = pos.pos_y;
        printf("Танк уперся в границу! Его текущая позиция (%d;%d)\n", tank->pos.pos_x, tank->pos.pos_y);
        return 1;
    }
    return 0;
}

// Функция проверки границ для снаряда
int checkBulletBorder(struct Bullet* bullet) {
    if (bullet->pos.pos_x < 0 || bullet->pos.pos_x >= 20 || bullet->pos.pos_y < 0 || bullet->pos.pos_y >= 20) return 1;
    return 0;
}

// Функция для перемещения пули
void moveBullet(struct Bullet* bullet) {
    while (bullet->isActive) {
        switch (bullet->direction) {
        case 0: bullet->pos.pos_x -= bullet->speed; break; 
        case 1: bullet->pos.pos_y += bullet->speed; break; 
        case 2: bullet->pos.pos_y += bullet->speed; break;
        case 3: bullet->pos.pos_x -= bullet->speed; break;
        }
        printf("Координаты снаряда (%d, %d) в направлении %d\n", bullet->pos.pos_x, bullet->pos.pos_y, bullet->direction);
        
        // Деактивировать пулю, если она вышла за пределы поля
        if (checkBulletBorder(bullet) == 1) { 
            bullet->isActive = 0;
            printf("Снаряд вышел за границы игрового поля в точке (%d;%d) и деактивирован\n", bullet->pos.pos_x, bullet->pos.pos_y);
        }
        //BulletHit(bullet);
    }
}

// Функция для стрельбы
void shootBullet(struct Player* player) {
    for (int i = 0; i < 5; i++) {
        if (player->tank.bullets[i].isActive == 0) {
            player->tank.bullets[i].pos.pos_x = player->tank.pos.pos_x;
            player->tank.bullets[i].pos.pos_y = player->tank.pos.pos_y;
            player->tank.bullets[i].direction = player->tank.direction;
            player->tank.bullets[i].isActive = 1;
            moveBullet(&player->tank.bullets[i]);
            return;  // Прерываем цикл, т.к. один снаряд выпущен
        }
    }
    printf("Нет доступных снарядов.\n");
}

// Функция попадания пули в танк противника
/*void BulletHit(struct Bullet* bullet) {
        if (bullet->pos.pos_x == enemy->pos_x && bullet->pos_y == enemyPlayer->pos_y) {
            enemyPlayer->life_count = 0;   // Уничтожение танка
            bullet->isActive = false;      // Деактивация пули
        }
}*/

// Функция для движения танка
void moveTankPlayer(struct Player& PlayerTank) {
    if (_kbhit()) {
        char key = _getch();  // Получить символ ввода
        switch (key) {
        case 'W': case 'w': 
            PlayerTank.tank.direction = 0; 
            if(!checkTankBorder(&PlayerTank.tank)) 
            PlayerTank.tank.pos.pos_y -= PlayerTank.tank.speed; 
            break;
        case 'D': case 'd': 
            PlayerTank.tank.direction = 1; 
            if (!checkTankBorder(&PlayerTank.tank))
            PlayerTank.tank.pos.pos_x += PlayerTank.tank.speed; 
            break;
        case 'S': case 's': 
            PlayerTank.tank.direction = 2;
            if (!checkTankBorder(&PlayerTank.tank))
            PlayerTank.tank.pos.pos_y += PlayerTank.tank.speed; 
            break;
        case 'A': case 'a': 
            PlayerTank.tank.direction = 3; 
            if (!checkTankBorder(&PlayerTank.tank))
            PlayerTank.tank.pos.pos_x -= PlayerTank.tank.speed; 
            break;
        case 'F': case 'f': shootBullet(&PlayerTank); break;
        }
        printf("Координаты танка: (%d;%d)\n", PlayerTank.tank.pos.pos_x, PlayerTank.tank.pos.pos_y);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    Game game;

    // Инициализация игры
    initGame(&game);

    // Основной игровой цикл
    while (!game.gameOver) {
        moveTankPlayer(game.player);
    }
    return 0;
}