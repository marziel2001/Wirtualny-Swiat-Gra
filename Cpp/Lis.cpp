#define INICJATYWA_LISA 7
#define SILA_LISA 3
#define ZNACZEK_LISA 'L'

#include "../naglowkowe/Lis.h"
#include "../naglowkowe/Swiat.h"

Lis::Lis(Swiat* swiat, Punkt polozenie)
{
	this->inicjatywa = INICJATYWA_LISA;
	this->polozenie = polozenie;
	this->sila = SILA_LISA;
	this->swiat = swiat;
	this->typ = LIS;
	this->znaczek = ZNACZEK_LISA;
	this->turaUrodzenia = swiat->GetTura();
	this->zyje = 1;
}
Lis::~Lis() {}
void Lis::Akcja()
{
	this->Ruch();
}
void Lis::Ruch()
{	
	Punkt noweMiejsce = this->swiat->LosujPoleObok(this->polozenie, ZASIEG_ZWIERZECIA);
	Organizm* przeszkoda = this->swiat->GetPlansza()[noweMiejsce.GetX()][noweMiejsce.GetY()];
	if (przeszkoda != nullptr && przeszkoda->GetZyje()==0)
	{
		this->WykonajRuch(noweMiejsce);
	} 
	else if (przeszkoda != nullptr && przeszkoda != this && przeszkoda->GetZyje()==1)	// cos stoi
	{
		if (przeszkoda->GetSila() <= this->sila)
		{
			przeszkoda->Kolizja(this);
		}
	}
}
string Lis::WypiszGatunek()
{
	return "lis";
}