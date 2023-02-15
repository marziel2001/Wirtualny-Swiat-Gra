#define SILA_MLECZA 0
#define ZNACZEK_MLECZA 'M'

#include "../naglowkowe/Mlecz.h"
#include "../naglowkowe/Swiat.h"

Mlecz::Mlecz(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ROSLIN;
	this->polozenie = polozenie;
	this->sila = SILA_MLECZA;
	this->swiat = swiat;
	this->typ = MLECZ;
	this->znaczek = ZNACZEK_MLECZA;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Mlecz::~Mlecz(){}
void Mlecz::Akcja()
{
	for (int i = 0; i < 3; i++) 
	{
		this->Rozprzestrzenianie();
	}
}

string Mlecz::WypiszGatunek()
{
	return "Mlecz";
}