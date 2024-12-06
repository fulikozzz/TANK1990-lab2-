#include "SpecialBonus.h"
#include "ostream"

SpecialBonus::SpecialBonus() : Bonus(), radius(0) {}

SpecialBonus::SpecialBonus(int x, int y, KindOf kind, int activity_time, int radius) : 
    Bonus(x, y, kind, activity_time), radius(radius) {}

SpecialBonus::~SpecialBonus() {}

int SpecialBonus::Get_Extra_Points() const {
    return radius;
}

void SpecialBonus::Set_Extra_Points(int radius) {
   this->radius = radius;
}

// Перегрузка оператора присваивания (присваивание объекта базового класса)
SpecialBonus& SpecialBonus::operator=(Bonus& base) {
    
    this->Set_Pos(base.Get_Pos());
    this->Set_Kind(base.Get_Kind());
    this->Set_Activity_Time(base.Get_Activity_Time());

    this->radius = 0;
    return *this;
}

std::ostream& operator<<(std::ostream& output, SpecialBonus& bonus) {
    output << "Bonus [Позиция: (" << bonus.Get_Pos().Get_PosX() << ", " << bonus.Get_Pos().Get_PosY()
        << "), Вид: " << bonus.Get_Kind()
        << ", Время активности: " << bonus.Get_Activity_Time() << "],"
        << "Радиус: " << bonus.Get_Extra_Points() << std::endl;
    return output;
}
