#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
public:
    Wilk(Swiat* swiat, Punkt polozenie);
    ~Wilk();

    string WypiszGatunek() override;
};