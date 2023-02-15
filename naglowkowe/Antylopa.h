#pragma once
#include "Zwierze.h"

class Antylopa :
    public Zwierze
{
public:
    Antylopa(Swiat* swiat, Punkt polozenie);
    ~Antylopa();

    void Ruch() override;

    void Kolizja(Organizm* atakujacy) override;

    string WypiszGatunek() override;
};