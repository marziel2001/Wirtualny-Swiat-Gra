#define INICJATYWA_WILKA 5
#define SILA_WILKA 9
#define ZNACZEK_WILKA 'W'

#include "../naglowkowe/Wilk.h"
#include "../naglowkowe/Swiat.h"

Wilk::Wilk(Swiat * swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_WILKA;
	this->polozenie = polozenie;
	this->sila = SILA_WILKA;
	this->swiat = swiat;
	this->typ = WILK;
	this->znaczek = ZNACZEK_WILKA;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Wilk::~Wilk() {}

string Wilk::WypiszGatunek()
{
	return "wilk";
}