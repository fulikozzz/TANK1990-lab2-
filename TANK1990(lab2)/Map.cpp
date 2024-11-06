#include "Map.h"
#include "Wall.h"


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
    Position pos(10,20);
    player_base.Set_Pos(pos);
    player_base.Set_Is_Destroyed(false);
    for (int i = 0; i < 3; i++) {
        Position pos(1, 5 + 5 * i);
        enemy_bases[i].Set_Pos(pos);
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
                    this->walls[j][i].Set_Type(EMPTY);
                    break;
                case 1:
                    this->walls[j][i].Set_Type(IRON);
                    break;
                case 2:
                    this->walls[j][i].Set_Type(WOOD);
                    break;
                case 3:
                    this->walls[j][i].Set_Type(BRIC_FULL);
                    break;
                case 4:
                    this->walls[j][i].Set_Type(BRICK_HALF);
                    break;
                case 5:
                    this->walls[j][i].Set_Type(BRICK_LOW);
                    break;
                case 6:
                    this->walls[j][i].Set_Type(WATER);
                    break;
                case 7:
                    this->walls[j][i].Set_Type(ICE);
                    break;
                case 8:
                    this->walls[j][i].Set_Type(BUSH);
                    break;
                case 9:
                    this->walls[j][i].Set_Type(EMPTY);
                    this->player_base.Get_Pos().Set_PosX(j);
                    this->player_base.Get_Pos().Set_PosY(i);
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

void Map::Draw(Player player, std::vector<Enemy>& enemies) {
    Wall temp_map[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (player.Get_Tank().Get_Pos().Get_PosX() == i && player.Get_Tank().Get_Pos().Get_PosY() == j)
                temp_map[i][j].Set_Type(PLAYER);
            else
                temp_map[i][j] = this->walls[i][j];
        }
        for (Enemy& enemy : enemies) {
            int enemy_x = enemy.Get_Tank().Get_Pos().Get_PosX();
            int enemy_y = enemy.Get_Tank().Get_Pos().Get_PosY();

            // Если враг находится в текущей клетке, меняем тип клетки
            if (enemy_x >= 0 && enemy_x < 20 && enemy_y >= 0 && enemy_y < 20) {
                temp_map[enemy_x][enemy_y].Set_Type(ENEMY);  // Устанавливаем тип клетки для врага
            }
        }
    }
    
    system("cls");
    this->LoadFromFile(1);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            switch (temp_map[j][i].Get_Type()) {
            case EMPTY:
                std::cout << "  "; // Свободно
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
            case PLAYER:
                std::cout << "P "; // игрок
                break;
            case ENEMY:
                std::cout << "E "; // игрок
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
            std::cout << "E" << " на позиции: (" << this->enemy_bases[i].Get_Pos().Get_PosX() << ", "
                << this->enemy_bases[i].Get_Pos().Get_PosY() << ")" << std::endl; // Отображение баз врагов
        }
    }

    std::cout << std::endl;
}