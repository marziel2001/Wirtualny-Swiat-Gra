#pragma once
#include "Roslina.h"

class BarszczSosnowskiego : public Roslina
{
public:
    BarszczSosnowskiego(Swiat* swiat, Punkt polozenie);
    ~BarszczSosnowskiego();

    void Akcja() override;
    void Kolizja(Organizm* atakujacy) override;

    string WypiszGatunek() override;
};