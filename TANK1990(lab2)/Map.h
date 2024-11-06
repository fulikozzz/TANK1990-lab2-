#pragma once
#include "Wall.h"
#include "Base.h"

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
    ~Map();
    void LoadFromFile(int level);
    void Draw();
};

