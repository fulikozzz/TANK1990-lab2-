#include "Game.h"
#include "Bonus.h"
#include "SpecialBonus.h"
#include <iostream>
#include <locale.h>

class gun{
public: 
    virtual void shoot() { cout << "gun shooting" << endl; }
};
class pistol : public gun {
public:
    void shoot() override { cout << "pistol shooting" << endl; }
};

int main() {
    setlocale(LC_ALL, "Rus");
    /* ВИРТУАЛЬНЫЕ ФУНКЦИИ */
    /*
    gun g;
    pistol p;
    g.shoot();
    p.shoot();
    gun* weapon = &g;
    weapon->shoot();
    weapon = &p;
    weapon->shoot();
    free(weapon);
    */
    /* КЛОНИРОВАНИЕ */
    /*
    Player original(Position(5, 5), 2, UP, 3, 100);
    original.Print_Info();
    std::cout << std::endl;

    // Поверхностное клонирование
    std::cout << "Поверхностное клонирование" << std::endl;
    Player* shallowCopy = original.CloneShallow();
    shallowCopy->Print_Info();
    std::cout << std::endl;

    // Глубокое клонирование
    std::cout << "Глубокое клонирование" << std::endl;
    Player* deepCopy = original.CloneDeep();
    deepCopy->Print_Info();
    std::cout << std::endl;

    delete shallowCopy;
    delete deepCopy;
    */
    /* КОНСТРУКТОРЫ БК СП из ПК СП */
    /*Position pos = Position(1, 5);
    Player p;
    p = Player(pos, 1, UP, 3, 10200);
    p.Print_Info();*/

    //Tank t;

    /* ПРИСВОЕНИЕ ОБЪЕКТУ ПРОИЗВОДНОГО КЛАССА ОБЪЕКТА БАЗОВОГО */
    /*Bonus b1(5, 12, LIFE, 15);
    SpecialBonus b2 (4,10, BULLET, 5, 5);
    std::cout << b1 << std::endl;
    std::cout << b2;
    b2 = b1;
    std::cout << b2 << std::endl;*/

    /* ЗАПРЕТ КОНСТРУКТОРА КОПИРОВАНИЯ ПО УМОЛЧАНИЮ */
    /*Bonus b1(5, 12, LIFE, 15);
    //Bonus b3(b1);
    Bonus b3(b1,1);
    std::cout << b1 << std::endl;
    std::cout << b3 << std::endl;*/

    Game game; 

    game.Level_Decide();

    while (!game.Get_Game_Is_Over()) {
        game.Update();  
    }
    return 0;
}