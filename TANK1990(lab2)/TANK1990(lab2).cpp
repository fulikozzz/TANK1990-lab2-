#include "Game.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    Game game;

    while (!game.Get_Game_Is_Over()) {
        game.Get_Player().Control();
        game.Update();  
        game.Bullet_Hit();
    }
    return 0;
}