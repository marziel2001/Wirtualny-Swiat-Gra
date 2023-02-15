#define INICJATYWA_ANTYLOPY 4
#define SILA_ANTYLOPY 4
#define ZNACZEK_ANTYLOPY 'A'
#define ZASIEG_ANTYLOPY 2

#include "../naglowkowe/Antylopa.h"
#include "../naglowkowe/Swiat.h"

void Antylopa::Ruch()
{
	Punkt noweMiejsce = this->swiat->LosujPoleObok(this->polozenie, ZASIEG_ANTYLOPY);
	if (!(noweMiejsce == this->polozenie))
	{
		Organizm* przeszkoda = this->swiat->GetPlansza()[noweMiejsce.GetX()][noweMiejsce.GetY()];

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
void Antylopa::Kolizja(Organizm* atakujacy)
{
	if (atakujacy->GetTyp() != this->GetTyp()) 
	{
		if (rand() % 100 > 50) 
		{
			Punkt nowePolozenie = this->swiat->LosujWolnePoleObok(this->polozenie,1);
		
			if (nowePolozenie == this->polozenie) // nie wylosowano pola do ucieczki wiec walczy
			{
				Zwierze::Kolizja(atakujacy);
			}
			else
			{
				this->swiat->DodajTekst(this->WypiszOrganizm() + " ucieka od: " + atakujacy->WypiszOrganizm());
				this->WykonajRuch(nowePolozenie);
			}
		}
	}
	else Zwierze::Kolizja(atakujacy);
}

string Antylopa::WypiszGatunek()
{
	return "antylopa";
}
Antylopa::Antylopa(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_ANTYLOPY;
	this->polozenie = polozenie;
	this->sila = SILA_ANTYLOPY;
	this->swiat = swiat;
	this->typ = ANTYLOPA;
	this->znaczek = ZNACZEK_ANTYLOPY;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Antylopa::~Antylopa() {}