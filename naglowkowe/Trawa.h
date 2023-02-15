#pragma once
#include "Roslina.h"

class Trawa : public Roslina
{
public:
    Trawa(Swiat* swiat, Punkt polozenie);
    ~Trawa();

    string WypiszGatunek() override;
};