#pragma once
#include "Roslina.h"

class Guarana : public Roslina
{
public:
    Guarana(Swiat* swiat, Punkt polozenie);
    ~Guarana();

    void Kolizja(Organizm* atakujacy) override;

    string WypiszGatunek() override;
};