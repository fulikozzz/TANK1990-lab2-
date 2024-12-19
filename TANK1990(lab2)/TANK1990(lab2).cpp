#include "Game.h"
/*
#include "Bonus.h"
#include "SpecialBonus.h"
*/
#include <iostream>
#include <locale.h>

#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>

/*
class gun {
public: 
    virtual void shoot() { cout << "gun shooting" << endl; }
};
class pistol : public gun {
public:
    void shoot() override { cout << "pistol shooting" << endl; }
};
*/

bool myBinPredicate(int a, int b) {
    return a > b;
}

int main() {
    setlocale(LC_ALL, "Rus");
    /*
    // ВИРТУАЛЬНЫЕ ФУНКЦИИ //
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
    //
    /* КЛОНИРОВАНИЕ //
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
    //
    /* КОНСТРУКТОРЫ БК СП из ПК СП //
    /*Position pos = Position(1, 5);
    Player p;
    p = Player(pos, 1, UP, 3, 10200);
    p.Print_Info();//

    //Tank t;

    // ПРИСВОЕНИЕ ОБЪЕКТУ ПРОИЗВОДНОГО КЛАССА ОБЪЕКТА БАЗОВОГО //
    /*Bonus b1(5, 12, LIFE, 15);
    SpecialBonus b2 (4,10, BULLET, 5, 5);
    std::cout << b1 << std::endl;
    std::cout << b2;
    b2 = b1;
    std::cout << b2 << std::endl;//

    /* ЗАПРЕТ КОНСТРУКТОРА КОПИРОВАНИЯ ПО УМОЛЧАНИЮ //
    /*Bonus b1(5, 12, LIFE, 15);
    //Bonus b3(b1);
    Bonus b3(b1,1);
    std::cout << b1 << std::endl;
    std::cout << b3 << std::endl;//

    /* ВИРТУАЛЬНЫЙ ДЕСТРУКТОР //
    /*std::cout << "\tЧерез указатели\n" << std::endl;
    Bonus* b1 = new Bonus();
    b1->~Bonus();
    std::cout << std::endl;
    Bonus* b2 = new SpecialBonus();
    b2->~Bonus();
    std::cout << "\n\tЧерез объекты\n" << std::endl;
    Bonus b3;
    b3.~Bonus();
    std::cout << std::endl;
    SpecialBonus b4;
    b4.~SpecialBonus();//*/

    /* Работа с разными контейнерами библиотеки STL */
    // Vector 
    std::vector<vector<int>> p = { {5,3,7}, {4,2,5,1,2} };
    //std::cout << p[1][1] << std::endl;
    //try {
      //  std::cout << p.at(1).at(1) << endl;
    //}
    //catch (std::out_of_range ex) {
      //  std::cout << ex.what() << endl;
    //}
    // Очистка вектора
    //p.at(0).clear();
    // Начало - конец вектора 
    // Итераторы
    //std::vector<int>::iterator it_s = p[1].begin();
    /*std::_Vector_iterator it_s = p[1].begin();
    std::_Vector_iterator it_e = p[1].end() - 1;
    std::cout << *it_s << " " << *it_e << std::endl << std::endl;
    std::cout << *++it_s << " " << *--it_e << std::endl << std::endl;*/
    // Резервирование места
    //p[1].reserve(10);
    // Доступное место
    //std::cout << p[1].capacity() << std::endl;
    //p[0].clear();
    //p[1].emplace(p[1].begin() + 3, 8);
    //p[1].insert(p[1].begin() + 3, 3);
    //p[1].pop_back();
    //p[1].push_back(999);
    //std::cout << p[1].data() << std::endl;
    //p[0].erase(p[0].begin() + 1);
    //p[1].erase(p[1].begin() + 1, p[1].end() - 2);
    //p[1].assign({ 0,2,5,3 });
    //p[1].swap(p[0]);
    // Сравнение 
    /*
    std::vector<char> s1 = { 's', 'f', 'f' };
    std::vector<char> s2 = { 's', 'a', 'f' };
    bool flag = (s1 == s2);
    std::cout << flag << std::endl << std::endl;
    */
    //Вывод вектора
    /*for (vector<int>& v_el : p) {
        for(int& element : v_el)
        std::cout << element << " ";
    }
    std::cout << std::endl;*/
    //List + Forward_List 
    std::list<int> myList = { 0, 3, 5, 1, 2, 2 };
    //auto iter = myList.end();
    //std::cout << *--iter << std::endl;
    //myList.unique(); // Оставляет уникальные элементы
    //myList.sort(); 
    //myList.push_back(888);
    //myList.push_front(2);
    //myList.unique();
    //myList.clear();
    //bool f = myList.empty();
    //std::cout << f << std::endl;
    // Вывод листа
    /*for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << endl;*/
    std::forward_list<int> myFList = { 0, 3, 5, 1, 2 };
    //myFList.push_front(52);
    //std::forward_list<int>::iterator iter = myFList.before_begin();
    //--iter; не существует перегрузки для --
    //++iter;
    //myFList.insert_after(iter,55);
    //myFList.emplace_front(53);
    //myFList.emplace_after(iter,53);
    //auto iterat = myFList.before_begin();
    //myFList.erase_after(iterat);
    // Вывод листа
    /*for (auto it : myFList) {
        std::cout << it << " "; 
    }
    std::cout << std::endl;*/
    // Array
    std::array<int, 4> myArr = { 2,3,4,5 };
    // Обертка для статического массива
    //myArr.fill(5);
    /*std::cout << myArr.front() << std::endl;
    for (int& item : myArr) {
        std::cout << item << std::endl;
    }*/
    // Deque
    std::deque<int> myDeque = { 0,1,2,3,4,5 };
    //std::cout << myDeque.at(5) << std::endl;
    //myDeque.assign({ 9, 3, 2 });
    //auto it = find(myDeque.begin(), myDeque.end(), 3);
    //myDeque.erase(it);
    //auto iter = myDeque.begin() + 3;
    //myDeque.emplace(iter, 53);
    //std::cout << myDeque.back() << std::endl;
    /*for (auto el : myDeque) {
        std::cout << el << std::endl;}*/
    /* Set + Multiset */
    std::set<int> mySet = { 0,3,2,4,95,1,8,2,2 };
    //mySet.emplace(43);
    //mySet.erase(2);
    //std::cout << *mySet.find(4) << std::endl; // Метод поиска (возвращает итератор)
    //std::cout << mySet.contains(223) << std::endl; // булевый результат нахождения элемента(содержится или нет)
    /*auto node = mySet.extract(8); // Метод извлечения какого-либо значения
    std::cout << node.value() << std::endl;
    mySet.emplace(node.value());*/
    /*for (auto el : mySet) {
        std::cout << el << std::endl;
    }*/
    std::multiset<int> myMultiSet = { 0,3,2,4,95,1,8,2,2 };
    //std::cout << myMultiSet.count(2) << std::endl << std::endl;
    //myMultiSet.erase(2);
    /*for (auto el : myMultiSet) {
        std::cout << el << std::endl;
    }*/
    /* Map + Multimap */
    std::map<string, int> myMap = { { "str", 1} , {"str1",2} };
    //myMap.emplace("str1", 19); //игнорируется
    //myMap.emplace("str2", 84); //добавляется
    //std::cout << myMap.find("str1")->second << std::endl; 
    /*for (auto el : myMap) {
        std::cout << el.first << "-" << el.second << std::endl;
    }*/
    std::multimap<int, int> myMultiMap = { {0, 1} , {1, 2} };
    //myMultiMap.emplace(0, 3);
    //myMultiMap.emplace(0, 5);   
    //myMultiMap.erase(0);
    //auto it = myMultiMap.find(0);
    /*auto range = myMultiMap.equal_range(0);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << " ";
    }*/
    /*for (auto el : myMultiMap) {
        std::cout << el.first << "-" << el.second << std::endl;
    }*/
    /* Stack */
    std::stack<int> myStack = {};
    //myStack._Get_container(); // container = std::deque<type>
    //myStack.push(53);
    //myStack.push(31);
    //myStack.emplace(0);
    /*while (!myStack.empty()) {
        std::cout << myStack.top() << std::endl;
        myStack.pop();
    }*/
    /* Queue */
    std::queue<int> myQueue= {};
    //myQueue.push(5);
    //myQueue.push(3);
    //myQueue.emplace(2);
    //std::cout << myQueue.front() << " " << myQueue.back() << std::endl;
    /*while (!myQueue.empty()) {
        std::cout << myQueue.front() << std::endl;
        myQueue.pop();
    }*/
    /* Priority_queue */
    std::priority_queue<int> myQueueP;
    //myQueueP.push(3);
    //myQueueP.push(5);
    //myQueueP.emplace(2);
    //std::cout << myQueueP.top() << std::endl;
    /*while (!myQueueP.empty()) {
        std::cout << myQueueP.top() << std::endl;
        myQueueP.pop();
    }*/


    /* СОРТИРОВКА */

    std::vector<int> unsortedV = { 0,95, 12, 53, 56, 32, 11, 8 };
    for (int& element : unsortedV) { std::cout << element << " "; }
    std::cout << std::endl;

    //Сортировка по уменьшению
    sort(unsortedV.begin(), unsortedV.end());
    for (int& element : unsortedV) { std::cout << element << " "; }
    std::cout << std::endl;

    //Сортировка по увеличению через лямбда-выражение
    sort(unsortedV.begin() + 4, unsortedV.end(), [](int a, int b) {
        return a > b;
        });
    for (int& element : unsortedV) { std::cout << element << " "; }
    std::cout << std::endl;

    //Сортировка по увеличению через функцию-предикат
    sort(unsortedV.begin(), unsortedV.end(), myBinPredicate);
    for (int& element : unsortedV) { std::cout << element << " "; }
    std::cout << std::endl;

    //Сортировка по четности и уменьшению
    sort(unsortedV.begin(), unsortedV.end(), [](int a, int b) {
        if ((a % 2 != 0) && (b % 2 == 0)) return true;  
        if ((a % 2 == 0) && (b % 2 != 0)) return false; 
        return a > b; }
    );
    for (int& element : unsortedV) { std::cout << element << " "; }
    std::cout << std::endl;



    std::cout << endl << endl << endl << endl << endl << endl;
    
    Game game;

    game.Level_Decide();

    while (!game.Get_Game_Is_Over()) {
        game.Update();
    }
    return 0;
}