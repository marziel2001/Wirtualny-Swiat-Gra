#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
public:
    Owca(Swiat* swiat, Punkt polozenie);
    ~Owca();

    string WypiszGatunek() override;
};