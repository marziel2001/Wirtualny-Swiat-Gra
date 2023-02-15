#define ILOSC_ORGANIZMOW 10

#include "../naglowkowe/Organizm.h"
#include "../naglowkowe/Swiat.h"
#include <iostream>
#include<string>

using namespace std;

Organizm::Organizm(Swiat * swiat) 
{
	this->inicjatywa = 0;
	this->polozenie = Punkt(0, 0);
	this->sila = 0;
	this->swiat = nullptr;
	this->turaUrodzenia = 0;
	this->typ = (TypOrganizmu)0;
	this->znaczek = ' ';
	this->zyje = 1;
}
Organizm::Organizm()
{}
Organizm::~Organizm()
{}

void Organizm::WykonajRuch(Punkt polozenie)	// finalne przesuniecie po ew. walidacji
{
	if (!(this->swiat->CzyPozaPlansza(polozenie)))
	{
		this->swiat->SetPlansza(this->polozenie.GetX(), this->polozenie.GetY(), nullptr);
		this->polozenie = polozenie;
		this->swiat->SetPlansza(polozenie.GetX(), polozenie.GetY(), this);
	}
}
void Organizm::Rysowanie()
{
	cout << znaczek;
}

int Organizm::GetSila()
{
	return this->sila;
}
bool Organizm::GetZyje()
{
	return zyje;
}
Swiat* Organizm::GetSwiat()
{
	return this->swiat;
}
int Organizm::GetInicjatywa()
{
	return this->inicjatywa;
}
Organizm::TypOrganizmu Organizm::GetTyp()
{
	return this->typ;
}
Punkt Organizm::GetPolozenie()
{
	return polozenie;
}
char Organizm::GetZnaczek()
{
	return znaczek;
}
int Organizm::GetTuraUrodzenia()
{
	return this->turaUrodzenia;
}

void Organizm::SetSila(int sila)
{
	this->sila = sila;
}
void Organizm::SetInicjatywa(int inicjatywa)
{
	this->inicjatywa = inicjatywa;
}
void Organizm::SetTypOrganizmu(TypOrganizmu typ)
{
	this->typ = typ;
}
void Organizm::SetPolozenie(Punkt polozenie)
{
	this->polozenie = polozenie;
}
void Organizm::SetZnaczek(char znaczek)
{
	this->znaczek = znaczek;
}
void Organizm::SetTuraUrodzenia(int tura)
{
	this->turaUrodzenia = tura;
}
string Organizm::WypiszOrganizm()
{
	string tekst = this->WypiszGatunek() + " x: "
		+ to_string(this->polozenie.GetX()) 
		+ " y: " + to_string(this->polozenie.GetY()) 
		+ " sila: " + to_string(this->GetSila());

	return tekst;
}
Organizm::TypOrganizmu Organizm::LosujTyp()
{
	return (TypOrganizmu)((rand() % (ILOSC_ORGANIZMOW))+1);
}
void Organizm::Zabij()
{
	this->zyje = 0;
}