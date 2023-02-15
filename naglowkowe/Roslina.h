#pragma once
#include "Organizm.h"
#define INICJATYWA_ROSLIN 0
#define ZASIEG_ROSLIN 1

class Roslina : public Organizm
{
public: 
    Roslina(Swiat* swiat, Punkt polozenie);
    Roslina();
    ~Roslina();

    bool GetCzyZwierze() override;

protected:
    virtual void Rozprzestrzenianie();    
    virtual void Akcja() override;
    virtual void Kolizja(Organizm* atakujacy) override;
    
private:
};