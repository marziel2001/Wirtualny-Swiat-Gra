#define INICJATYWA_OWCY 4
#define SILA_OWCY 4
#define ZNACZEK_OWCY 'O'

#include "../naglowkowe/Owca.h"
#include "../naglowkowe/Swiat.h"

Owca::Owca(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_OWCY;
	this->polozenie = polozenie;
	this->sila = SILA_OWCY;
	this->swiat = swiat;
	this->typ = OWCA;
	this->znaczek = ZNACZEK_OWCY;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Owca::~Owca() {}

string Owca::WypiszGatunek()
{
	return "owca";
}