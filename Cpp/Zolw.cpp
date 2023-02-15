#define INICJATYWA_ZOLWIA 1
#define SILA_ZOLWIA 2
#define ZNACZEK_ZOLWIA 'Z'

#include "../naglowkowe/Zolw.h"
#include "../naglowkowe/Swiat.h"

using namespace std;

Zolw::Zolw(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ZOLWIA;
	this->polozenie = polozenie;
	this->sila = SILA_ZOLWIA;
	this->swiat = swiat;
	this->typ = ZOLW;
	this->znaczek = ZNACZEK_ZOLWIA;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Zolw::~Zolw() {}

void Zolw::Akcja()
{
	if (rand() % 100 > 75) 
	{
		this->Ruch();	
	}
}
void Zolw::Kolizja(Organizm* atakujacy)
{
	if (this->GetTyp() == atakujacy->GetTyp())
	{
		this->Rozmnazaj();
	} 
	else if (atakujacy->GetSila() > 5)
	{
		if (this->CzyWygralWalke(atakujacy))
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " zabija " + atakujacy->WypiszOrganizm());
			this->swiat->UsunOrganizm(atakujacy);
		}
		else
		{
			this->swiat->DodajTekst(atakujacy->WypiszOrganizm() + " zabija " + this->WypiszOrganizm());
			this->swiat->UsunOrganizm(this);
		}
	} 
	else
	{
		this->swiat->DodajTekst(this->WypiszOrganizm() + " odpiera atak " + atakujacy->WypiszOrganizm());
	}
}
string Zolw::WypiszGatunek()
{
	return "zolw";
}