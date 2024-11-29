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
    
    Bonus bonus1(6, 7, LIFE, 30);
    Bonus bonus2(3, 1, INVULNERABILITY, 20);

    // Вывод
    std::cout << "Bonus 1: " << bonus1 << std::endl;
    std::cout << "Bonus 2: " << bonus2 << std::endl;

    // Сложение 
    Bonus bonus3 = bonus1 + bonus2;
    std::cout << "Bonus 3 (Bonus1 + Bonus2): " << bonus3 << std::endl;

    // Унарный минус
    Bonus bonus4 = -bonus1;
    std::cout << "Bonus 4 (-Bonus1): " << bonus4 << std::endl;

    // Равенство
    bool areEqual = bonus1 == bonus2;
    std::cout << "Bonus 1 и Bonus 2 равны? " << (areEqual ? "Да" : "Нет") << std::endl;

    // Присвоение
    Bonus bonus5 = bonus1;
    std::cout << "Bonus 5: " << bonus5 << std::endl;
    
    int a = 1, b = 2, c = func_address(a,b);
    std::cout << c  << " " << &c << endl;
    int e = 5, f = 2; int *g = func_pointer(e, f);
    std::cout << *g << " " << &g << endl;
    
    Player p = Player();
    
    Game game,
        game1(game); // Вызов конструктора копирования
    game.Level_Decide();
    while (!game1.Get_Game_Is_Over()) {
        game1.Update();  
    }
    game1.Level_Decide();
    while (!game.Get_Game_Is_Over()) {
        game.Update();
    }
    return 0;
}