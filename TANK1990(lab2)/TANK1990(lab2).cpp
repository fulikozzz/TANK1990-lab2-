#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Танк игрока
struct PlayerTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
};

// Танк противника
struct EnemyTank {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
};

// Снаряд
struct Bullet {
    int pos_x;
    int pos_y;
    int vector;
    int speed;
};

// Игровое поле
struct PlayField {
    int size_x;
    int size_y;
    int** grid;
};

// Инициализация игрового поля
void initPlayField(struct PlayField* field, int size_x, int size_y) {
    field->size_x = size_x;
    field->size_y = size_y;

    field->grid = (int**)malloc(size_x * sizeof(int*));
    field->grid = (int**)malloc(size_y * sizeof(int*));

    // Заполняем поле
    for (int i = 0; i < size_x; i++) {
        for (int j = 0; j < size_y; j++) {
            field->grid[i][j] = 0;
        }
    }
    printf("Игровое поле проинициализировано с размерами %d x %d\n", size_x, size_y);
}

// Функция для очистки памяти игрового поля
void freePlayField(struct PlayField* field) {
    for (int i = 0; i < field->size_x; i++) {
        free(field->grid[i]);
    }
    free(field->grid);
    printf("Игровое поле удалено\n");
}

int main()
{
    setlocale(LC_ALL, "Rus");
    struct PlayField field;
    // Инициализация обьектов
    initPlayField(&field, 100, 100);



    // Освобождение ресурсов
    freePlayField(&field);
    return 0;
}
