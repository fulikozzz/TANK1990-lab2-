#pragma once
#include "Bonus.h"

class SpecialBonus : public Bonus
{
private: 
	int radius; 
	// например, суперсила для уничтожения всех танков в определенном радиусе

public:
    SpecialBonus();
    SpecialBonus(int x, int y, KindOf kind, int activity_time, int radius);
    ~SpecialBonus();

    int Get_Extra_Points() const;
    void Set_Extra_Points(int radius);

    SpecialBonus& operator=(Bonus& base);
    
    friend std::ostream& operator<<(std::ostream& output, SpecialBonus& bonus);
};



