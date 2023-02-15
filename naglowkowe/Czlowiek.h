#pragma once
#include "Zwierze.h"
#include "Swiat.h"

class Czlowiek : public Zwierze
{
public:
    Czlowiek(Swiat* swiat, Punkt polozenie);
    ~Czlowiek();

    void Akcja() override;
    void Kolizja(Organizm * atakujacy) override;

    void SetNastepnyRuch(Swiat::Kierunek kierunek);
    void zmniejszCooldownIUmiejetnosc();
    void WlaczUmiejetnosc();
    bool CzyUmiejetnoscAktywna();
    string WypiszGatunek() override;

protected:

private:
    Swiat::Kierunek nastepnyRuch;
    int cooldown;
    int zostaloUmiejetnosci;
};