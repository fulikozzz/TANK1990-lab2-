#include "Game.h"

#include <iostream>
#include <locale.h>

int main() {
   
    setlocale(LC_ALL, "Rus");
    Game game;

    while (!game.Get_Game_Is_Over()) {
        game.Update();  
    }
    return 0;
}