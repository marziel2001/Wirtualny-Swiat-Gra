#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
public:
    Lis(Swiat* swiat, Punkt polozenie);
    ~Lis();

    void Akcja() override;
    void Ruch() override;

    string WypiszGatunek() override;
};