#include "Game.h"

#include <iostream>
#include <locale.h>

//Задание с возвратом результата по указателю и по ссылке
int& func_address(int ax, int bx) {
    int cx = ax + bx;
    return cx;
}

int* func_pointer(int ax, int bx) {
    int* cx = new int;
    *cx = ax + bx;
    return cx;
}



int main() {
   
    setlocale(LC_ALL, "Rus");
    Player p = Player();

    int a = 1, b = 2, c = func_address(a,b);
    std::cout << c  << " " << &c << endl;
    int e = 5, f = 2; int *g = func_pointer(e, f);
    std::cout << *g << " " << &g << endl;

    Game game,
        game1(game); // Вызов конструктора копирования

    while (!game1.Get_Game_Is_Over()) {
        game1.Update();  
    }
    while (!game.Get_Game_Is_Over()) {
        game.Update();
    }
    return 0;
}