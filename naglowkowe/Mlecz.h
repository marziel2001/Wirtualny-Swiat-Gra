#pragma once
#include "Roslina.h"

class Mlecz : public Roslina
{
public:
    Mlecz(Swiat* swiat, Punkt polozenie);
    ~Mlecz();

    void Akcja() override;
    string WypiszGatunek() override;
};