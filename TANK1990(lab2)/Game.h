#pragma once
#include "Bullet.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Bonus.h"

#include <vector>

using namespace std;

class Game
{
private:
    bool game_is_over;
	int level;
    Map map;
    Player player;
    int amount_of_enemies;
    vector <Enemy> enemies;

public:
    Game();
    Game(const Game& other);
    ~Game();

    bool Get_Game_Is_Over();
    int Get_Level();
    int Get_Amoun_Of_Enemies();
    Player& Get_Player();
    std::vector<Enemy>& Get_Enemies();
    Map Get_Map();
    
    void Set_Game_Is_Over(bool game_is_over);
    void Set_Level(int level);
    void Set_Amoun_Of_Enemies(int amount_of_enemies);
    void Set_Enemies(const std::vector<Enemy>& newEnemies);

    void Initialize_Enemies(int amount_of_enemies);
    bool Bullet_Hit();
    void Update();
    bool Victory_Check();

    bool Check_Border(Tank& tank, int width, int height);
    bool Check_Border(const Bullet& bullet, const int width, const int height);
};

