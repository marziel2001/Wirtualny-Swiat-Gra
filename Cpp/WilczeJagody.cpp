#define SILA_JAGOD 99
#define ZNACZEK_JAGOD 'J'

#include "../naglowkowe/WilczeJagody.h"
#include "../naglowkowe/Swiat.h"

WilczeJagody::WilczeJagody(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ROSLIN;
	this->polozenie = polozenie;
	this->sila = SILA_JAGOD;
	this->swiat = swiat;
	this->typ = WILCZE_JAGODY;
	this->znaczek = ZNACZEK_JAGOD;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
WilczeJagody::~WilczeJagody() {}
void WilczeJagody::Kolizja(Organizm* atakujacy)
{
	if (atakujacy->GetCzyZwierze())
	{
		this->swiat->DodajTekst( atakujacy->WypiszOrganizm()+ " zjada " + this->WypiszOrganizm() + " i umiera. ");

		this->swiat->UsunOrganizm(atakujacy);
		this->swiat->UsunOrganizm(this);
	}
}

string WilczeJagody::WypiszGatunek()
{
	return "wilczeJagody";
}
