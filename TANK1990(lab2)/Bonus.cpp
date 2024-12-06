#include "Bonus.h"

Bonus::Bonus() {
	this->pos.Set_PosX(0);
	this->pos.Set_PosY(0);
	this->kind = LIFE;
	this->activity_time = 0;
    std::cout << "Бонус создан" << std::endl;
}

Bonus::Bonus(int x, int y, KindOf kind, int activity_time) {
	this->pos.Set_PosX(x);
	this->pos.Set_PosY(y);
	this->kind = kind;
	this->activity_time = activity_time;

}

/*Bonus::Bonus(const Bonus& other) {
	this->pos = other.pos;
	this->kind = other.kind;
	this->activity_time = other.activity_time;
}*/

Bonus::Bonus(const Bonus& other, int x) {
    this->pos = other.pos;
    this->kind = other.kind;
    this->activity_time = other.activity_time;
}

Bonus::~Bonus() {
    std::cout << "Бонус удален" << std::endl;
}

Position Bonus::Get_Pos() { return pos; }

KindOf Bonus::Get_Kind() { return kind; }

int Bonus::Get_Activity_Time() { return activity_time; }

void Bonus::Set_Pos(Position position) {
	pos.Set_PosX(position.Get_PosX());
	pos.Set_PosY(position.Get_PosY());
}

void Bonus::Set_Kind(KindOf kind) { this->kind = kind; }

void Bonus::Set_Activity_Time(int activity_time) { this->activity_time = activity_time; }


/* Перегрузка операторов*/
/*
Bonus& Bonus::operator=(Bonus other) {
    this->pos = other.pos;
    this->kind = other.kind;
    this->activity_time = other.activity_time;
    return *this;
}

Bonus Bonus::operator+(Bonus other) {
    Bonus result;
    result.pos.Set_PosX(this->pos.Get_PosX() + other.pos.Get_PosX());
    result.pos.Set_PosY(this->pos.Get_PosY() + other.pos.Get_PosY());
    result.kind = (KindOf)((this->kind + other.kind) % 4);
    result.activity_time = this->activity_time + other.activity_time;
    return result;
}

Bonus Bonus::operator-() {
    Bonus result;
    result.pos.Set_PosX(-this->pos.Get_PosX());
    result.pos.Set_PosY(-this->pos.Get_PosY());
    result.kind = this->kind;
    result.activity_time = -this->activity_time;
    return result;
}

bool Bonus::operator==(Bonus& other) {
    return this->pos.Get_PosX() == other.pos.Get_PosX() &&
        this->activity_time == other.activity_time &&
        this->kind == other.kind;

}
*/
std::ostream& operator<<(std::ostream& output, Bonus& bonus) {
    output << "Bonus [Позиция: (" << bonus.pos.Get_PosX() << ", " << bonus.pos.Get_PosY()
        << "), Вид: " << bonus.kind
        << ", Время активности: " << bonus.activity_time << "]";
    return output;
}

