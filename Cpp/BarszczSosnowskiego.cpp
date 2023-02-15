#define SILA_BARSZCZU 10
#define ZNACZEK_BARSZCZU 'B'

#include "../naglowkowe/BarszczSosnowskiego.h"
#include "../naglowkowe/Swiat.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ROSLIN;
	this->polozenie = polozenie;
	this->sila = SILA_BARSZCZU;
	this->swiat = swiat;
	this->typ = BARSZCZ_SOSNOWSKIEGO;
	this->znaczek = ZNACZEK_BARSZCZU;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
BarszczSosnowskiego::~BarszczSosnowskiego()
{
}

void BarszczSosnowskiego::Akcja()
{	
	// zabija wszystkie zwierzeta dookola
	int x = this->GetPolozenie().GetX();
	int y = this->GetPolozenie().GetY();

	if (x > 0 && this->swiat->GetPlansza()[x - 1][y] != nullptr) 
	{
		if (this->swiat->GetPlansza()[x - 1][y]->GetZyje()==1&&this->swiat->GetPlansza()[x - 1][y]->GetCzyZwierze())
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " zabija " + this->swiat->GetPlansza()[x - 1][y]->WypiszOrganizm());
			this->swiat->UsunOrganizm(this->swiat->GetPlansza()[x - 1][y]);
		}
	}
	if (x < this->swiat->GetX()-1 && this->swiat->GetPlansza()[x + 1][y] != nullptr)
	{
		if (this->swiat->GetPlansza()[x + 1][y]->GetZyje()==1 && this->swiat->GetPlansza()[x + 1][y]->GetCzyZwierze())
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " zabija " + this->swiat->GetPlansza()[x + 1][y]->WypiszOrganizm());
			this->swiat->UsunOrganizm(this->swiat->GetPlansza()[x + 1][y]);
		}
	}
	if (y > 0 && this->swiat->GetPlansza()[x][y - 1] != nullptr)
	{
		if (this->swiat->GetPlansza()[x][y - 1]->GetZyje() ==1&& this->swiat->GetPlansza()[x][y - 1]->GetCzyZwierze())
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " zabija " + this->swiat->GetPlansza()[x][y - 1]->WypiszOrganizm());
			this->swiat->UsunOrganizm(this->swiat->GetPlansza()[x][y - 1]);
		}
	}
	if (y < this->swiat->GetY() - 1 && this->swiat->GetPlansza()[x][y + 1] != nullptr)
	{
		if (this->swiat->GetPlansza()[x][y + 1]->GetZyje() == 1 && this->swiat->GetPlansza()[x][y + 1]->GetCzyZwierze())
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " zabija " + this->swiat->GetPlansza()[x][y + 1]->WypiszOrganizm());
			this->swiat->UsunOrganizm(this->swiat->GetPlansza()[x][y + 1]);
		}
	}

	this->Rozprzestrzenianie();
}
void BarszczSosnowskiego::Kolizja(Organizm* atakujacy)
{
	if (atakujacy->GetCzyZwierze())
	{
		this->swiat->UsunOrganizm(atakujacy);
		this->swiat->UsunOrganizm(this);
	}
}

string BarszczSosnowskiego::WypiszGatunek()
{
	return "BarszczSosnowskiego";
}
