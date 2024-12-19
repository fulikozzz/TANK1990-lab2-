#include "Player.h"
#include "Position.h"

#include <conio.h>
#include <iostream>

Player::Player(): Tank(), lives(3), score(0){
    behaviour = new MoveWithKeyboard();
}

Player::Player(Position pos, int speed, Direction dir, int lives, int score) :
    Tank(new MoveWithKeyboard(), pos, dir, speed, 1), lives(lives), score(score) {
}

Player::Player(const Player& other) {
    this->pos = other.pos;
    this->speed = other.speed;
    this->direction = other.direction;
    this->armor = other.armor;
    this->lives = other.lives;
    this-> score= other.score;
}

Player::~Player() { 
}

//Tank& Player::Get_Tank() { return this->tank; }

int Player::Get_Lives() { return lives; }

int Player::Get_Score() { return score; }

//void Player::Set_Tank(Tank tank) { this->tank = tank; }

void Player::Set_Lives(int lives) { this->lives = lives; }

void Player::Set_Score(int score) { this->score = score; }

void Player::Move() {
    if (!Check_Border()) {
        behaviour->Move(this->pos, this->direction, this->speed);
    }
    /*Direction dir = Get_Direction();
    switch (dir) {
    case UP:
        if (!Check_Border()) pos.Set_PosY(pos.Get_PosY() - Get_Speed());
        break;
    case RIGHT:
        if (!Check_Border()) pos.Set_PosX(pos.Get_PosX() + Get_Speed());
        break;
    case DOWN:
        if (!Check_Border()) pos.Set_PosY(pos.Get_PosY() + Get_Speed());
        break;
    case LEFT:
        if (!Check_Border()) pos.Set_PosX(pos.Get_PosX() - Get_Speed());
        break;
    }*/
}

void Player::Shoot() {
    // Алгоритм поиска по условию
    // Найти первый неактивный снаряд
    auto it = std::find_if(bullets.begin(), bullets.end(), [](Bullet& bullet) {
        return !bullet.Get_IsActive();
        }
    );

    // Если найден неактивный снаряд, выстрелить его
    if (it != bullets.end()) {
        it->Set_Pos(Position(pos));     
        it->Set_Direction(direction);  
        it->Set_IsActive(true);        
        it->Move();                    
    }
}

bool Player::Control() {
    if (_kbhit()) {
        char key = _getch();  
        switch (key) {
        case 'W': case 'w':
            Set_Direction(UP);
            Move();
            break;
        case 'D': case 'd':
            Set_Direction(RIGHT);
            Move();
            break;
        case 'S': case 's':
            Set_Direction(DOWN);
            Move();
            break;
        case 'A': case 'a':
            Set_Direction(LEFT);
            Move();
            break;
        case 'F': case 'f': Shoot();
            break;
        }
        return true;
    }
    return false;
}

Player* Player::CloneShallow() const {
    Player* clone = new Player(*this);
    return clone;
}

Player* Player::CloneDeep() const {
    Player* deepCopy = new Player(*this);

    deepCopy->bullets.clear();
    for (const Bullet& bullet : this->bullets) {
        deepCopy->bullets.push_back(bullet); 
    }
    return deepCopy;
}

void Player::Print_Info() {
    std::cout << "Player Info:" << std::endl;
    std::cout << "Position: (" << pos.Get_PosX() << ", " << pos.Get_PosY() << ")" << std::endl;
    std::cout << "Speed: " << speed << std::endl;
    std::cout << "Direction: " << direction << std::endl;
    std::cout << "Armor: " << armor << std::endl;
    std::cout << "Lives: " << lives << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "Bullets: " << bullets.size() << " bullets" << std::endl;
    for (size_t i = 0; i < bullets.size(); ++i) {
        Bullet& bullet = bullets[i];
        std::cout << "  Bullet " << i + 1 << ": Position ("
            << bullet.Get_Pos().Get_PosX() << ", "
            << bullet.Get_Pos().Get_PosY() << "), "
            << "Active: " << bullet.Get_IsActive() << std::endl;
    }
}