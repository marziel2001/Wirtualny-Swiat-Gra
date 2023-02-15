#define SILA_TRAWY 0
#define ZNACZEK_TRAWY 'T'

#include "../naglowkowe/Trawa.h"
#include "../naglowkowe/Swiat.h"

Trawa::Trawa(Swiat * swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ROSLIN;
	this->polozenie = polozenie;
	this->sila = SILA_TRAWY;
	this->swiat = swiat;
	this->typ = TRAWA;
	this->znaczek = ZNACZEK_TRAWY;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Trawa::~Trawa() {}

string Trawa::WypiszGatunek()
{
	return "trawa";
}