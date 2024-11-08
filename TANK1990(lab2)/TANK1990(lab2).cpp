#include "Game.h"

#include <iostream>
#include <locale.h>

int main() {
    // Задание 5 лабораторной работы
    // 1. Динамический массив объектов класса Enemy
    int numEnemies = 3;
    Enemy* enemiesArray = new Enemy[numEnemies];  
    
    for (int i = 0; i < numEnemies; ++i) {
        enemiesArray[i].Set_Armor(1);  
        std::cout << "Enemy " << i + 1 << " armor: " << enemiesArray[i].Get_Armor() << std::endl;
    }
    // Удаляем динамический массив
    delete[] enemiesArray;
    
    // 2. Массив динамических объектов класса Enemy
    Enemy* dynamic_enemies[3];

    for (int i = 0; i < 3; ++i) {
        dynamic_enemies[i] = new Enemy();  
        dynamic_enemies[i]->Set_Armor((i + 1) * 2);
        std::cout << "Dynamic Enemy " << i + 1 << " armor: " << dynamic_enemies[i]->Get_Armor() << std::endl;
    }

    // Освобождаем память
    for (int i = 0; i < 3; ++i) {
        delete dynamic_enemies[i];
    }

    // Игра
    setlocale(LC_ALL, "Rus");
    Game game;

    while (!game.Get_Game_Is_Over()) {
        game.Update();  
    }
    return 0;
}