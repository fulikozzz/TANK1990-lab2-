#pragma once
#include "Wall.h"
#include "Base.h"
#include "Player.h"
#include "Enemy.h"

#include <string>
using namespace std;

class Map
{
private:
    Wall walls[20][20];
    Base player_base;
    Base enemy_bases[3];

public:
    Map();
    Map(const Map& other);
    ~Map();

    void LoadFromFile(int level);
    void Draw(int level, Player player, std::vector<Enemy>& enemies);
};

