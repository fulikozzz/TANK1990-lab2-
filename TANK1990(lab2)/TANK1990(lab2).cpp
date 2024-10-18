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
struct Enemies {
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
struct Base {
    struct Position pos;
    int isDestroyed;
};

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
    int enemy_count = 3;
    struct Enemies* enemy;
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
            map->walls[i][j].pos.pos_x = i;  
            map->walls[i][j].pos.pos_y = j;  
            map->walls[i][j].type = 1;        
        }
    }
    // Инициализация бонусов
    for (int i = 0; i < 4; i++) {
        map->bonuses[i].pos.pos_x = rand() % 20;  
        map->bonuses[i].pos.pos_y = rand() % 20;  
        map->bonuses[i].type = rand() % 2;         
        map->bonuses[i].isActive = 1;              
    }
    printf("Игровое поле проинициализировано с размерами 20 * 20\n");
}
// Иницицализация снаряда
void initBullet(struct Bullet* bullet) {
    bullet->isActive = 0;
    bullet->speed = 1;
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
    printf("Игровок проинициализирован на координатах (%d;%d) с направлением %d\n", player->tank.pos.pos_x, player->tank.pos.pos_y, player->tank.direction);
}

// Инициализацмя противника
void initEnemies(struct Game* game) {
    game->enemy = (struct Enemies*)malloc(game->enemy_count * sizeof(struct Enemies));
    for (int i = 0; i < game->enemy_count; i++) {
        game->enemy[i].tank.pos.pos_x = 19;
        game->enemy[i].tank.pos.pos_y = 19;
        game->enemy[i].tank.direction = 0;
        game->enemy[i].tank.speed = 1;
        for (int j = 0; j < 5; j++) initBullet(&game->enemy[i].tank.bullets[j]);
        printf("Противник %d проинициализирован на координатах (%d;%d) с направлением %d\n", i+1, game->enemy[i].tank.pos.pos_x, game->enemy[i].tank.pos.pos_y, game->enemy[i].tank.direction);
    }
}

// Освобождение памяти
void freeEnemies(struct Game* game) {
    free(game->enemy);  
    printf("Память очищена.\n");
}

// Инициадизация игры
void initGame(struct Game* game) {
    game->level = 1;
    game->gameOver = 0;
    initMap(&game->map);  // Инициализация карты
    initPlayer(&game->player);  // Инициализация игрока
    initEnemies(game); // Инициализация противника
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
    if (bullet->pos.pos_x < 0 || bullet->pos.pos_y < 0 || bullet->pos.pos_x >= 20 || bullet->pos.pos_y >= 20) return 1;
    return 0;
}

// Функция попадания пули в танк противника
void BulletHit(struct Bullet* bullet, struct Enemies* enemies, int enemy_count) {
    for (int i = 0; i < enemy_count; i++) {
        // Проверка попадания пули в танк противника
        if (bullet->isActive &&
            bullet->pos.pos_x == enemies[i].tank.pos.pos_x &&
            bullet->pos.pos_y == enemies[i].tank.pos.pos_y) {
            // Уничтожение танка противника
            enemies[i].tank.pos.pos_x = -1;
            enemies[i].tank.pos.pos_y = -1;
            bullet->isActive = 0;  // Деактивация пули
            enemy_count -= 1;
            printf("Снаряд попал в противника на позиции (%d;%d) и уничтожил его.\n", bullet->pos.pos_x, bullet->pos.pos_y);
            return;  // Прерываем цикл, так как пуля попала
        }
    }
}

// Функция для перемещения пули
void moveBullet(struct Bullet* bullet, struct Enemies* enemy, int enemyCount) {
    while (bullet->isActive) {
        switch (bullet->direction) {
        case 0: bullet->pos.pos_y -= bullet->speed; break; 
        case 1: bullet->pos.pos_x += bullet->speed; break; 
        case 2: bullet->pos.pos_y += bullet->speed; break;
        case 3: bullet->pos.pos_x -= bullet->speed; break;
        }
        printf("Координаты снаряда (%d, %d) в направлении %d\n", bullet->pos.pos_x, bullet->pos.pos_y, bullet->direction);
        
        // Деактивировать пулю, если она вышла за пределы поля
        if (checkBulletBorder(bullet) == 1) bullet->isActive = 0;
        BulletHit(bullet, enemy, enemyCount);
    }
}

// Функция для стрельбы
void shootBullet(struct Player* player, struct Enemies* enemy, int enemyCount) {
    for (int i = 0; i < 5; i++) {
        if (player->tank.bullets[i].isActive == 0) {
            player->tank.bullets[i].pos.pos_x = player->tank.pos.pos_x;
            player->tank.bullets[i].pos.pos_y = player->tank.pos.pos_y;
            player->tank.bullets[i].direction = player->tank.direction;
            player->tank.bullets[i].isActive = 1;
            moveBullet(&player->tank.bullets[i], enemy, enemyCount);
            return;  // Прерываем цикл, т.к. один снаряд выпущен
        }
    }
    printf("Нет доступных снарядов.\n");
}

// Функция для движения танка
void moveTankPlayer(struct Player* PlayerTank, struct Enemies* enemies, int enemyCount) {
    if (_kbhit()) {
        char key = _getch();  // Получить символ ввода
        switch (key) {
        case 'W': case 'w': 
            PlayerTank->tank.direction = 0; 
            if(!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.pos_y -= PlayerTank->tank.speed; 
            break;
        case 'D': case 'd': 
            PlayerTank->tank.direction = 1;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.pos_x += PlayerTank->tank.speed;
            break;
        case 'S': case 's': 
            PlayerTank->tank.direction = 2;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.pos_y += PlayerTank->tank.speed; 
            break;
        case 'A': case 'a': 
            PlayerTank->tank.direction = 3;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.pos_x -= PlayerTank->tank.speed;
            break;
        case 'F': case 'f': shootBullet(PlayerTank, enemies, enemyCount); break;
        }
        printf("Координаты танка: (%d;%d), Направление: %d \n", PlayerTank->tank.pos.pos_x, PlayerTank->tank.pos.pos_y, PlayerTank->tank.direction);
    }
}

// Функция проверки победы
void checkWin(struct Game* game) {
    int remainingEnemies = 0;
    for (int i = 0; i < game->enemy_count; i++) {
        if (game->enemy[i].tank.pos.pos_x != -1) {
            remainingEnemies++;
        }
    }
    if (remainingEnemies == 0) {
        printf("Вы победили!\n");
        game->gameOver = 1;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    Game game;

    // Инициализация игры
    initGame(&game);

    while (!game.gameOver) {
        moveTankPlayer(&game.player, game.enemy, game.enemy_count);
        checkWin(&game);
    }

    freeEnemies(&game);
    return 0;
}