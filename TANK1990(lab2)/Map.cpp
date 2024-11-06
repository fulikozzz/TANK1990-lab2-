#include "Map.h"
#include "Wall.h"
#include "Player.h"

#include <fstream>
#include <iostream>
#include <filesystem>

Map::Map() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            this->walls[i][j].Get_Pos().Set_PosX(i);
            this->walls[i][j].Get_Pos().Set_PosY(j);
            this->walls[i][j].Set_Type(EMPTY);
        }
    }
    player_base.Get_Pos().Set_PosX(10);
    player_base.Get_Pos().Set_PosY(20);
    player_base.Set_Is_Destroyed(false);
    for (int i = 0; i < 3; i++) {
        enemy_bases[i].Get_Pos().Set_PosX(5+5*i);
        enemy_bases[i].Get_Pos().Set_PosY(1);
        enemy_bases[i].Set_Is_Destroyed(false);
    }
    printf("Игровое поле проинициализировано с размерами 20 * 20\n");
}

Map::~Map() {

}

void Map::LoadFromFile(int level) {
    std::string directoryPath = std::filesystem::current_path().string();
    string filename = "map_" + std::to_string(level) + ".txt";
    
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    string line;
    for (int i = 0; i < 20; ++i) {
        if (getline(file, line)) {
            for (int j = 0; j < 20; ++j) {
                int symbol = line[j] - '0'; 
                //std::cout << symbol;
                switch (symbol)
                {
                case 0:
                    this->walls[i][j].Set_Type(EMPTY);
                    break;
                case 1:
                    this->walls[i][j].Set_Type(IRON);
                    break;
                case 2:
                    this->walls[i][j].Set_Type(WOOD);
                    break;
                case 3:
                    this->walls[i][j].Set_Type(BRIC_FULL);
                    break;
                case 4:
                    this->walls[i][j].Set_Type(BRICK_HALF);
                    break;
                case 5:
                    this->walls[i][j].Set_Type(BRICK_LOW);
                    break;
                case 6:
                    this->walls[i][j].Set_Type(WATER);
                    break;
                case 7:
                    this->walls[i][j].Set_Type(ICE);
                    break;
                case 8:
                    this->walls[i][j].Set_Type(BUSH);
                case 9:
                    this->walls[i][j].Set_Type(EMPTY);
                    this->player_base.Get_Pos().Set_PosX(i);
                    this->player_base.Get_Pos().Set_PosY(j);
                    this->player_base.Set_Is_Destroyed(false);
                    break;
                default:
                    break;
                }
            }
            //std::cout << "\n";
        }
        else {
            cerr << "Ошибка чтения строки " << i + 1 << std::endl;
            break;
        }
    }
    file.close();
}

void Map::Draw() { 
    system("cls");
    this->LoadFromFile(1);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            switch (walls[i][j].Get_Type()) {
            case EMPTY:
                std::cout << ". "; // Свободно
                break;
            case IRON:
                std::cout << "# "; // Железная стена
                break;
            case WOOD:
                std::cout << "W "; // Деревянная стена
                break;
            case BRIC_FULL:
                std::cout << "B "; // Полная кирпичная стена
                break;
            case BRICK_HALF:
                std::cout << "b "; // Полукирпичная стена
                break;
            case BRICK_LOW:
                std::cout << "l "; // Низкая кирпичная стена
                break;
            case WATER:
                std::cout << "~ "; // Вода
                break;
            case ICE:
                std::cout << "I "; // Лёд
                break;
            case BUSH:
                std::cout << "b "; // Куст
                break;
            default:
                break;
            }
        }
        
        std::cout << std::endl;
    }

    std::cout << "Base"; // Отображение базы игрока, можно изменить символ
    std::cout << " на позиции: (" << this->player_base.Get_Pos().Get_PosX() << ", "
        << player_base.Get_Pos().Get_PosY() << ")" << std::endl;

    
    for (int i = 0; i < 3; i++) {
        if (!enemy_bases[i].Get_Is_Destroyed()) {
            std::cout << "E" << " на позиции: (" << enemy_bases[i].Get_Pos().Get_PosX() << ", "
                << enemy_bases[i].Get_Pos().Get_PosY() << ")" << std::endl; // Отображение баз врагов
        }
    }

    std::cout << std::endl;
}