#include "Game.h"

#include <iostream>

Game::Game() {
    this->game_is_over = false;
	this->level = 1;
    this->amount_of_enemies = 4;
    this->map = Map();
    this->player = Player();
    Initialize_Enemies(amount_of_enemies);
}

Game::~Game() {
    this->enemies.clear(); 
}

bool Game::Get_Game_Is_Over() { return this->game_is_over; }

int Game::Get_Level() { return this->level; }

int Game::Get_Amoun_Of_Enemies() { return this->amount_of_enemies; }

Player& Game::Get_Player() { return this->player; }

std::vector<Enemy>& Game::Get_Enemies() {
    return this->enemies;
}

Map Game::Get_Map() { return this->map; }

void Game::Set_Game_Is_Over(bool game_is_over) { this->game_is_over = game_is_over; }

void Game::Set_Level(int level) { this->level = level; }

void Game::Set_Amoun_Of_Enemies(int amount_of_enemies) { this->amount_of_enemies = amount_of_enemies; }

void Game::Set_Enemies(const std::vector<Enemy>& newEnemies) { this->enemies = newEnemies; }

void Game::Initialize_Enemies(int amount_of_enemies) {
    enemies.resize(amount_of_enemies); 

    for (int i = 0; i < amount_of_enemies; i++) {
        Tank tank;
        Position pos(rand() % 20, rand() % 20);
        tank.Set_Pos(pos);
        tank.Set_Direction(UP); 
        tank.Set_Speed(1); 

        this->enemies[i].Set_Tank(tank); 
        enemies[i].Set_Armor(1); 
    }
}

bool Game::Victory_Check() {
    if (enemies.empty()) { 
        this->game_is_over = true;
        return true;
    }
    else return false;
}

bool Game::Bullet_Hit(){
    bool hitDetected = false; 

    for (int i = 0; i < this->amount_of_enemies; i++) {
        for (Bullet& bullet : this->player.Get_Tank().Get_Bullets()) {
           if (bullet.Get_IsActive() &&
                bullet.Get_Pos().Get_PosX() == this->enemies[i].Get_Tank().Get_Pos().Get_PosX() &&
                bullet.Get_Pos().Get_PosY() == this->enemies[i].Get_Tank().Get_Pos().Get_PosY()) {
                
                bullet.Set_IsActive(false);
                enemies.erase(enemies.begin() + i);
                this->amount_of_enemies -= 1;

                hitDetected = true;
                break; 
            }
        }
        if (hitDetected) break;
    }
    return hitDetected; 
}

void Game::Update() {
    if (this->player.Control()) {
        this->map.Draw(this->level, this->player, this->Get_Enemies());
        for (int i = 0; i < this->amount_of_enemies; i++) {
            std::cout << "Противник " << i + 1
                << " находится на координатах ("
                << enemies[i].Get_Tank().Get_Pos().Get_PosX() << ";"
                << enemies[i].Get_Tank().Get_Pos().Get_PosY() << ") с направлением "
                << enemies[i].Get_Tank().Get_Direction() << std::endl;
        }
    }

    for (Bullet& bullet : this->player.Get_Tank().Get_Bullets()) {
        if (bullet.Get_IsActive()) {
            if (Bullet_Hit()) std::cout << "Снаряд попал в противника на позиции (" << bullet.Get_Pos().Get_PosX() << ";" << bullet.Get_Pos().Get_PosY() << ") и уничтожил его. " << std::endl;
            bullet.Move();
            std::cout << "Координаты снаряда (" << bullet.Get_Pos().Get_PosX() << ";" 
                << bullet.Get_Pos().Get_PosY() << ") в направлении (" << bullet.Get_Direction() << ")" << std::endl;
        }
    }

    if(Victory_Check()) std::cout << "\nВы победили!" << std::endl;
}
 