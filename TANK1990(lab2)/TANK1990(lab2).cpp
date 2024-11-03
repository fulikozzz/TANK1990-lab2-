#include "Position.h"
#include "Bullet.h"
#include "Player.h"

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

// Игрок
/*struct Player {
    Tank tank;
    int lives;
    int score;
};*/

// Противник
struct Enemies {
    Tank tank;
};

// Бонус
struct Bonus {
    Position pos;
    int type;
    int isActive;
};

// Стены
struct Wall {
    Position pos;
    int type;
};

// База игрока
struct Base {
    Position pos;
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
    Player player;
    int enemy_count;
    struct Enemies* enemy;
    int gameOver;
};

/* ИНИЦИАЛИЗАЦИЯ */
// Инициализация позиции
/*void initPosition(struct Position* pos) {
    pos->pos_x = 0;
    pos->pos_y = 0;
}*/

// Инициализация игрового поля
void initMap(struct Map* map) {
    // Инициализация стен
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            map->walls[i][j].pos.Set_PosX(i);
            map->walls[i][j].pos.Set_PosY(j);
            map->walls[i][j].type = 1;
        }
    }
    // Инициализация бонусов
    for (int i = 0; i < 4; i++) {
        map->bonuses[i].pos.Set_PosX(rand() % 20);
        map->bonuses[i].pos.Set_PosY(rand() % 20);
        map->bonuses[i].type = rand() % 2;
        map->bonuses[i].isActive = 1;
    }
    printf("Игровое поле проинициализировано с размерами 20 * 20\n");
}
// Иницицализация снаряда
/*void initBullet(struct Bullet* bullet) {
    bullet->isActive = 0;
    bullet->speed = 1;
    bullet->bulletType = 0;
}*/

// Инициализация игрока
/*void initPlayer(Player* player) {
    player->Set_Lives(3);
    player->Set_Score(0);
    player->tank.pos.Set_PosX(1);
    player->tank.pos.Set_PosY(1);
    player->tank.direction = 0;
    player->tank.speed = 1;
   // for (int i = 0; i < 5; i++) initBullet(&player->tank.bullets[i]);
    printf("Игровок проинициализирован на координатах (%d;%d) с направлением %d\n", player->Get_Tank().Get_Pos().Get_PosX(), player->Get_Tank().Get_Pos().Get_PosY(), player->Get_Tank().Get_Direction());
}*/

// Инициализацмя противника
void initEnemies(struct Game* game) {
    game->enemy = (struct Enemies*)malloc(game->enemy_count * sizeof(struct Enemies));
    for (int i = 0; i < game->enemy_count; i++) {
        game->enemy[i].tank.Get_Pos().Set_PosX(19);
        game->enemy[i].tank.Get_Pos().Set_PosY(19);
        game->enemy[i].tank.Set_Direction(UP);
        game->enemy[i].tank.Set_Speed(1);
        //for (int j = 0; j < 5; j++) initBullet(&game->enemy[i].tank.bullets[j]);*/
        printf("Противник %d проинициализирован на координатах (%d;%d) с направлением %d\n", i + 1, game->enemy[i].tank.Get_Pos().Get_PosX(), game->enemy[i].tank.Get_Pos().Get_PosY(), game->enemy[i].tank.Get_Direction());
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
    game->enemy_count = 3;
    initMap(&game->map);  // Инициализация карты
    //initPlayer(&game->player);  // Инициализация игрока
    initEnemies(game); // Инициализация противника
}

// Функция проверки границ для танка
/*int checkTankBorder(struct Tank* tank) {
    Position pos(tank->pos.Get_PosX(), tank->pos.Get_PosY());
    int direction = tank->direction;
    if (direction == 0 && pos.Get_PosY() - tank->speed < 0 ||
        direction == 1 && pos.Get_PosX() + tank->speed >= 20 ||
        direction == 2 && pos.Get_PosY() + tank->speed >= 20 ||
        direction == 3 && pos.Get_PosX() - tank->speed < 0) {
        tank->pos.Set_PosX(pos.Get_PosX());
        tank->pos.Set_PosY(pos.Get_PosY()); 
        printf("Танк уперся в границу! Его текущая позиция (%d;%d)\n", tank->pos.Get_PosX(), tank->pos.Get_PosY());
        return 1;
    }
    return 0;
}*/

// Функция проверки границ для снаряда
/*int checkBulletBorder(struct Bullet* bullet) {
    if (bullet->pos.Get_PosX() < 0 || bullet->pos.Get_PosY() < 0 || bullet->pos.Get_PosX() >= 20 || bullet->pos.Get_PosY() >= 20) return 1;
    return 0;
}*/

// Функция попадания пули в танк противника
void BulletHit(Bullet* bullet, struct Enemies* enemies, int enemy_count) {
    for (int i = 0; i < enemy_count; i++) {
        // Проверка попадания пули в танк противника
        if (bullet->Get_IsActive() &&
            bullet->Get_Pos().Get_PosX() == enemies[i].tank.Get_Pos().Get_PosX() &&
            bullet->Get_Pos().Get_PosY() == enemies[i].tank.Get_Pos().Get_PosY()) {
            // Уничтожение танка противника
            enemies[i].tank.Get_Pos().Set_PosX(-1);
            enemies[i].tank.Get_Pos().Set_PosY(-1);
            bullet->Set_IsActive(false);  // Деактивация пули
            enemy_count -= 1;
            printf("Снаряд попал в противника на позиции (%d;%d) и уничтожил его.\n", bullet->Get_Pos().Get_PosX(), bullet->Get_Pos().Get_PosY());
            return;  // Прерываем цикл, так как пуля попала
        }
    }
}

// Функция для перемещения пули
/*void moveBullet(struct Bullet* bullet, struct Enemies* enemy, int enemyCount) {
    while (bullet->isActive) {
        switch (bullet->direction) {
        case 0: bullet->pos.Set_PosY(bullet->pos.Get_PosY() - bullet->speed); break;
        case 1: bullet->pos.Set_PosX(bullet->pos.Get_PosX() + bullet->speed); break;
        case 2: bullet->pos.Set_PosY(bullet->pos.Get_PosY() + bullet->speed); break;
        case 3: bullet->pos.Set_PosX(bullet->pos.Get_PosX() + bullet->speed); break;
        }
        printf("Координаты снаряда (%d, %d) в направлении %d\n", bullet->pos.Get_PosX(), bullet->pos.Get_PosY(), bullet->direction);

        // Деактивировать пулю, если она вышла за пределы поля
        if (checkBulletBorder(bullet) == 1) bullet->isActive = 0;
        BulletHit(bullet, enemy, enemyCount);
    }
}

// Функция для стрельбы
void shootBullet(struct Player* player, struct Enemies* enemy, int enemyCount) {
    for (int i = 0; i < 5; i++) {
        if (player->tank.bullets[i].Get_IsActive() == 0) {
            //player->tank.bullets[i].pos.Set_PosX(player->tank.pos.Get_PosX());
        //    player->tank.bullets[i].pos.Set_PosY(player->tank.pos.Get_PosY());
          //  player->tank.bullets[i].Set_Direction(player->tank.direction);
            player->tank.bullets[i].Set_IsActive(true);
            //moveBullet(&player->tank.bullets[i], enemy, enemyCount);
            player->tank.bullets[i].Move();
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
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.Set_PosY(PlayerTank->tank.pos.Get_PosY() - PlayerTank->tank.speed);
            break;
        case 'D': case 'd':
            PlayerTank->tank.direction = 1;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.Set_PosX(PlayerTank->tank.pos.Get_PosX() + PlayerTank->tank.speed);
            break;
        case 'S': case 's':
            PlayerTank->tank.direction = 2;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.Set_PosY(PlayerTank->tank.pos.Get_PosY() + PlayerTank->tank.speed);
            break;
        case 'A': case 'a':
            PlayerTank->tank.direction = 3;
            if (!checkTankBorder(&PlayerTank->tank)) PlayerTank->tank.pos.Set_PosX(PlayerTank->tank.pos.Get_PosX() - PlayerTank->tank.speed);
            break;
        case 'F': case 'f': shootBullet(PlayerTank, enemies, enemyCount); break;
        }
        printf("Координаты танка: (%d;%d), Направление: %d \n", PlayerTank->tank.pos.Get_PosX(), PlayerTank->tank.pos.Get_PosY(), PlayerTank->tank.direction);
    }
}*/

// Функция проверки победы
void checkWin(struct Game* game) {
    int remainingEnemies = 0;
    for (int i = 0; i < game->enemy_count; i++) {
        if (game->enemy[i].tank.Get_Pos().Get_PosX() != -1){
            remainingEnemies++;
        }
    }
    if (remainingEnemies == 0) {
        printf("Вы победили!\n");
        game->gameOver = 1;
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    Game game;

    // Инициализация игры
    initGame(&game);

    while (!game.gameOver) {
        game.player.Get_Tank().Control();
        checkWin(&game);
    }

    freeEnemies(&game);
    return 0;
}