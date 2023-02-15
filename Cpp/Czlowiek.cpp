#include "../naglowkowe/Czlowiek.h"
#include "../naglowkowe/Swiat.h"
#include <conio.h>

#define INICJATYWA_CZLOWIEKA 4
#define SILA_CZLOWIEKA 5
#define ZNACZEK_CZLOWIEKA 'C'
#define COOLDOWN_TIME 5
#define UMIEJETNOSC_TIME 5

Czlowiek::Czlowiek(Swiat * swiat, Punkt polozenie)
{	
	this->swiat = swiat;
	this->polozenie = polozenie;
	this->inicjatywa = INICJATYWA_CZLOWIEKA;
	this->sila = SILA_CZLOWIEKA;
	this->znaczek = ZNACZEK_CZLOWIEKA;
	this->turaUrodzenia = swiat->GetTura();
	this->typ = CZLOWIEK;
	this->nastepnyRuch = Swiat::Kierunek::BRAK;
	this->zostaloUmiejetnosci = 0;
	this->cooldown = 0;
	this->zyje = 1;
}
Czlowiek::~Czlowiek(){}

void Czlowiek::Akcja()
{	
	this->zmniejszCooldownIUmiejetnosc();

	Punkt noweMiejsce = this->polozenie;

		if (this->nastepnyRuch == Swiat::Kierunek::PRAWO)
		{
			noweMiejsce.SetX(this->polozenie.GetX() + 1);
		}
		else if (this->nastepnyRuch == Swiat::Kierunek::LEWO)
		{
			noweMiejsce.SetX(this->polozenie.GetX() - 1);
		}
		else if (this->nastepnyRuch == Swiat::Kierunek::DOL)
		{
			noweMiejsce.SetY(this->polozenie.GetY() + 1);
		}
		else if (this->nastepnyRuch == Swiat::Kierunek::GORA)
		{
			noweMiejsce.SetY(this->polozenie.GetY() - 1);
		}

		if (!(this->polozenie == noweMiejsce)) 
		{
			if (!(this->swiat->CzyPozaPlansza(noweMiejsce)))
			{
				Organizm* przeszkoda = this->swiat->GetPlansza()[noweMiejsce.GetX()][noweMiejsce.GetY()];

				if (przeszkoda != nullptr)	// cos stoi
				{
					if (przeszkoda->GetZyje() == 1)
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
			}
		}
}
void Czlowiek::Kolizja(Organizm* atakujacy)
{
	if (this->CzyUmiejetnoscAktywna())
	{
		if (atakujacy->GetSila() < this->sila)
		{
			Zwierze::Kolizja(atakujacy);
		}
		else
		{
			this->swiat->DodajTekst(this->WypiszOrganizm() + " odbija atak " + atakujacy->WypiszOrganizm());
		}
	}
	else
	{
		Zwierze::Kolizja(atakujacy);
	}
}
void Czlowiek::SetNastepnyRuch(Swiat::Kierunek kierunek)
{
	this->nastepnyRuch = kierunek;
}
void Czlowiek::zmniejszCooldownIUmiejetnosc()
{
	if(this->cooldown>0)
	{
		this->cooldown--;
	}
	if (this->zostaloUmiejetnosci > 0) 
	{
		this->zostaloUmiejetnosci--;
	}
}
void Czlowiek::WlaczUmiejetnosc()
{
	if (this->cooldown == 0)
	{
		this->swiat->DodajTekst("Aktywacja niesmiertelnosci czlowieka");
		this->zostaloUmiejetnosci = UMIEJETNOSC_TIME;
		this->cooldown = COOLDOWN_TIME + UMIEJETNOSC_TIME;
	}
	else cout << "musisz odczekac jeszcze " << this->cooldown << " tur.";
}
bool Czlowiek::CzyUmiejetnoscAktywna()
{
	if (this->zostaloUmiejetnosci > 0)
	{
		return true;
	}
	else return false;
}
string Czlowiek::WypiszGatunek()
{
	return "Czlowiek";
}