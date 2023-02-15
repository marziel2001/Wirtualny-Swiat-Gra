#define SILA_GUARANY 0
#define ZNACZEK_GUARANY 'G'

#include "../naglowkowe/Guarana.h"
#include "../naglowkowe/Swiat.h"

Guarana::Guarana(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ROSLIN;
	this->polozenie = polozenie;
	this->sila = SILA_GUARANY;
	this->swiat = swiat;
	this->typ = GUARANA;
	this->znaczek = ZNACZEK_GUARANY;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Guarana::~Guarana() {}

void Guarana::Kolizja(Organizm* atakujacy)
{
	atakujacy->SetSila(atakujacy->GetSila() + 3);
	this->swiat->DodajTekst(atakujacy->WypiszOrganizm() + " zjada " + this->WypiszOrganizm() + ", otrzymuje +3 do sily");

	this->swiat->UsunOrganizm(this);
}
string Guarana::WypiszGatunek()
{
	return "guarana";
}