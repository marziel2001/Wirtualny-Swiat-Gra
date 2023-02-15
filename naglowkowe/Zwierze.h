#pragma once
#define ZASIEG_ZWIERZECIA 1
#define SZANSA_ROZMNOZENIA 50

#include "Organizm.h"

class Zwierze :
public Organizm
{
public:
    bool GetCzyZwierze() override;
    void Rozmnazaj();
    virtual bool CzyWygralWalke(Organizm * atakujacy); 
    
    Zwierze();
    ~Zwierze();
private:

protected:  
    virtual void Akcja() override;
    virtual void Kolizja(Organizm * atakujacy) override;
    virtual void Ruch();

    Punkt przyszlePole;    
};