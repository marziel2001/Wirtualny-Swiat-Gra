#pragma once
#include <vector>
#include <iostream>
#include "Organizm.h"
#include "Punkt.h"

using namespace std;

class Organizm;
class Czlowiek;

class Swiat
{
public:
	enum Kierunek
	{
		GORA,
		PRAWO,
		DOL,
		LEWO,
		BRAK
	};

	Swiat(int x, int y);
	Swiat();
	~Swiat();

	void WykonajTure();
	void RysujSwiat();
	void DodajOrganizm(Organizm * organizm);
	void UsunOrganizm(Organizm* organizm);

	int GetX();
	int GetY();
	int GetTura();
	bool GetKoniec();
	bool GetCzlowiekZyje();
	Organizm*** GetPlansza();
	void SetPlansza(int x, int y, Organizm * pointer);
	vector<Organizm*> GetOrganizmy();
	Organizm * GetCzlowiek();

	void SetKoniec();
	void CzyscWektor();

	static Kierunek LosujKierunek();
	Punkt LosujWolnePole();
	Punkt LosujPoleObok(Punkt polozenie, int zasieg);
	Punkt LosujWolnePoleObok(Punkt polozenie, int zasieg);
	bool CzyPozaPlansza(Punkt polozenie);

	void DodajTekst(string tekst);
	void Input(); 
	static Swiat* WczytajZPliku();

void WypiszOrganizmy();
private:
	static string komunikat;
	int x, y;
	int tura;
	bool nastTura;
	bool koniec;
	Organizm*** plansza;
	vector<Organizm*> organizmy;
	Czlowiek* czlowiek;
	void SortujOrganizmy();
	static bool PorownajOrganizmy(Organizm * o1, Organizm * o2);
	void WypelnijSwiat();
	void ZapiszDoPliku();
	void StworzPlansze(int x, int y);
	void WyswietlKomunikat();
	void CzyscTekst();
protected:	
};