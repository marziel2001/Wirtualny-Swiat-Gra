#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina
{
public:
    void Kolizja(Organizm* atakujacy) override;
    string WypiszGatunek() override;  
    
    WilczeJagody(Swiat* swiat, Punkt polozenie);
    ~WilczeJagody();
};