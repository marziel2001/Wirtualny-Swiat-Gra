#include "../naglowkowe/Zwierze.h"
#include "../naglowkowe/Swiat.h"
#include <iostream>
#include "../naglowkowe/KreatorOrganizmow.h"
#include "../naglowkowe/Czlowiek.h"

void Zwierze::Akcja()
{
	this->Ruch();
}
void Zwierze::Ruch() 
{
	Punkt noweMiejsce = this->swiat->LosujPoleObok(this->polozenie, ZASIEG_ZWIERZECIA);

	if (!(noweMiejsce == this->polozenie)) 
	{
		Organizm * przeszkoda = this->swiat->GetPlansza()[noweMiejsce.GetX()][noweMiejsce.GetY()];

			if (przeszkoda != nullptr)	// cos stoi
			{		
				if (przeszkoda->GetZyje()==1)
				{
					przeszkoda->Kolizja(this);
					if (!przeszkoda->GetZyje())
					{
						this->WykonajRuch(noweMiejsce);
					}
				}
				else
				{
					this->WykonajRuch(noweMiejsce);
				}
			}
			else
			{
				this->WykonajRuch(noweMiejsce);
			}

	} // else nie ma miejsca na planszy
}
void Zwierze::Kolizja(Organizm* atakujacy) 
{
	if (this->GetTyp() == atakujacy->GetTyp())
	{
		if(atakujacy->GetTuraUrodzenia()!=this->swiat->GetTura())
		{
			this->Rozmnazaj();
		}	
	}
	else
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
}
void Zwierze::Rozmnazaj()
{
	if (rand() % 100 < SZANSA_ROZMNOZENIA)
	{
		Punkt WolnePole = this->swiat->LosujWolnePoleObok(this->polozenie, 1);

		if (!(WolnePole == this->polozenie)) 
		{
			Organizm* organizm = KreatorOrganizmow::StworzNowyOrganizm(this->typ, WolnePole, this->swiat);
			this->swiat->DodajTekst(this->WypiszOrganizm() + " rozmnaza sie");
			this->swiat->DodajOrganizm(organizm);
		}
	}
} 

Zwierze::Zwierze(){}
Zwierze::~Zwierze(){}

bool Zwierze::CzyWygralWalke(Organizm* atakujacy)
{
	if (this->sila > atakujacy->GetSila())
	{
		return true;
	}
	else if (this->sila < atakujacy->GetSila())
	{
		return false;
	}
	else if (this->sila == atakujacy->GetSila())
	{
		return false;
	}
}
bool Zwierze::GetCzyZwierze()
{
	return true;
}