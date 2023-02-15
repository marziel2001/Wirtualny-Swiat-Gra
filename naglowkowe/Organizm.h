#pragma once

using namespace std;

#include "Punkt.h"
#include <string>

class Swiat;
class Czlowiek;

class Organizm
{
public:
	enum TypOrganizmu
	{
		CZLOWIEK,//0
		WILK, 
		OWCA,
		LIS,
		ZOLW,
		ANTYLOPA,
		TRAWA,
		MLECZ,
		GUARANA,
		WILCZE_JAGODY,
		BARSZCZ_SOSNOWSKIEGO//10
	};
	
	Organizm(Swiat* swiat);
	Organizm();
	~Organizm();

	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* atakujacy) = 0;

	void Rysowanie(); 
	void WykonajRuch(Punkt polozenie);

	virtual bool GetCzyZwierze() = 0;

	virtual string WypiszGatunek() = 0;
	string WypiszOrganizm();

	static TypOrganizmu LosujTyp();

	void SetSila(int sila);
	void SetInicjatywa(int inicjatywa);
	void SetTypOrganizmu(TypOrganizmu typ);
	void SetPolozenie(Punkt polozenie);
	void SetZnaczek(char znaczek);
	void SetTuraUrodzenia(int tura);

	int GetSila();
	bool GetZyje();
	Swiat* GetSwiat();
	int GetInicjatywa();
	TypOrganizmu GetTyp();
	Punkt GetPolozenie();
	char GetZnaczek();
	int GetTuraUrodzenia();
	void Zabij();

private:
	
protected:
	int sila;
	int inicjatywa;
	Punkt polozenie;
	Swiat* swiat;
	TypOrganizmu typ;
	char znaczek;
	int turaUrodzenia;
	bool zyje;
};