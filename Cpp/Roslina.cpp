#include <iostream>
#include "../naglowkowe/Roslina.h"
#include "../naglowkowe/KreatorOrganizmow.h"
#include "../naglowkowe/Swiat.h"

#define SZANSA_ZASIANIA 80

void Roslina::Akcja()
{
	this->Rozprzestrzenianie();
}
void Roslina::Kolizja(Organizm* atakujacy) 
{
	if (atakujacy->GetCzyZwierze())
	{
		this->swiat->DodajTekst(atakujacy->WypiszOrganizm() + " zjada " + this->WypiszOrganizm());
		this->swiat->UsunOrganizm(this);
	}
}
void Roslina::Rozprzestrzenianie()
{	
	if ((rand() % 100) > SZANSA_ZASIANIA)
	{
		Punkt nowePole = this->swiat->LosujWolnePoleObok(this->polozenie, ZASIEG_ROSLIN);
		if (!(nowePole==this->polozenie))
		{
			Organizm* organizm = KreatorOrganizmow::StworzNowyOrganizm(this->typ, nowePole, this->swiat);
			this->swiat->DodajTekst("Wyrasta nowa " + this->WypiszOrganizm());
			this->swiat->DodajOrganizm(organizm);
		}
	}
}
bool Roslina::GetCzyZwierze()
{
	return false;
}

Roslina::Roslina(Swiat* swiat, Punkt polozenie) {}
Roslina::Roslina() {}
Roslina::~Roslina() {}