#include "Game.h"

#include <iostream>

int Game::level = 1;

Game::Game() {
    this->game_is_over = false;
	this->level = 1;
    this->amount_of_enemies = 2;
    this->map = Map();
    this->player = Player();
    //**
    enemies = std::make_unique<std::vector<Enemy>>();
    Initialize_Enemies(amount_of_enemies);
}

Game::Game(const Game& other) {
    this->game_is_over = other.game_is_over;
    this->level = other.level;
    this->amount_of_enemies = other.amount_of_enemies + 2; // Для отражения работы конструктора копирования
    this->map = other.map;
    this->player = other.player;
    enemies = std::make_unique<std::vector<Enemy>>(*other.enemies);
    //this->enemies = other.enemies;
    Initialize_Enemies(this->amount_of_enemies);
    std::cout << "Вызов конструктора копирования" << endl; // Для отражения работы конструктора копирования
}

Game::~Game() {
    //this->enemies.clear(); 
}

bool Game::Get_Game_Is_Over() { return game_is_over; }

int Game::Get_Level() { return level; }

int Game::Get_Amoun_Of_Enemies() { return amount_of_enemies; }

Player& Game::Get_Player() { return player; }

std::vector<Enemy>& Game::Get_Enemies() { return *enemies; /* return enemies;*/ }

Map Game::Get_Map() { return map; }

void Game::Set_Game_Is_Over(bool game_is_over) { this->game_is_over = game_is_over; }

void Game::Set_Level(int new_level) { level = new_level; }

void Game::Set_Amoun_Of_Enemies(int amount_of_enemies) { this->amount_of_enemies = amount_of_enemies; }

void Game::Set_Enemies(const std::vector<Enemy>& newEnemies) { *enemies = newEnemies; /**enemies = newEnemies;*/ }

void Game::Initialize_Enemies(int amount_of_enemies) {
    //enemies.resize(amount_of_enemies);
    enemies->resize(amount_of_enemies); 

    for (int i = 0; i < amount_of_enemies; i++) {
        Enemy enemy; 
        //Tank tank;
        Position pos(rand() % 20, rand() % 20);
        enemy.Set_Pos(pos);
        enemy.Set_Direction(UP); 
        enemy.Set_Speed(1); 

        //enemies[i] = enemy;
        //enemies[i].Set_Armor(1);
        enemies->at(i) = enemy;
        enemies->at(i).Set_Armor(1);
    }
}

bool Game::Victory_Check() {
    // if(enemies.empty()){
    if (enemies->empty()) {
        game_is_over = true;
        return true;
    }
    else return false;
}

bool Game::Bullet_Hit(){
    bool hitDetected = false; 

    for (int i = 0; i < this->amount_of_enemies; i++) {
        for (Bullet& bullet : this->player.Get_Bullets()) {
           if (bullet.Get_IsActive() &&
                bullet.Get_Pos()->Get_PosX() == this->enemies->at(i).Get_Pos().Get_PosX() &&
                bullet.Get_Pos()->Get_PosY() == this->enemies->at(i).Get_Pos().Get_PosY()) {
                
                bullet.Set_IsActive(false);
                enemies->erase(enemies->begin() + i);
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
    if (player.Control()) {
        map.Draw(level, player, Get_Enemies());
        for (int i = 0; i < amount_of_enemies; i++) {
            std::cout << "Противник " << i + 1
                << " находится на координатах ("
                << enemies->at(i).Get_Pos().Get_PosX() << ";"
                << enemies->at(i).Get_Pos().Get_PosY() << ") с направлением "
                << enemies->at(i).Get_Direction() << std::endl;
        }
    }

    for (Bullet& bullet : player.Get_Bullets()) {
        if (bullet.Get_IsActive()) {
            if (Bullet_Hit()) std::cout << "Снаряд попал в противника на позиции (" << bullet.Get_Pos()->Get_PosX() << ";" << bullet.Get_Pos()->Get_PosY() << ") и уничтожил его. " << std::endl;
            bullet.Move();
            std::cout << "Координаты снаряда (" << bullet.Get_Pos()->Get_PosX() << ";" 
                << bullet.Get_Pos()->Get_PosY() << ") в направлении (" << bullet.Get_Direction() << ")" << std::endl;
        }
    }

    if(Victory_Check()) std::cout << "\nВы победили!" << std::endl;
}

int Game::Level_Decide() {
    cout << "Введите номер уровня: ";
    int inp_level;
    try {
        cin >> inp_level;
        if (inp_level < 0)
            throw invalid_argument("Введен неверный номер!");
        else if (inp_level > 3)
            throw invalid_argument("Введен невозможный номер!");
        else Set_Level(inp_level);
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << "Установлен уровень 1" << endl;
        Set_Level(1);
    }
}
