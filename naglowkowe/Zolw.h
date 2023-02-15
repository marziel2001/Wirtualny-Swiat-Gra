#pragma once
#include "Zwierze.h"
class Zolw :
    public Zwierze
{
public:  
    void Akcja() override;
    void Kolizja(Organizm* atakujacy) override;

    Zolw(Swiat* swiat, Punkt polozenie);
    ~Zolw();

    string WypiszGatunek() override;
protected:
};