#include "../naglowkowe/Swiat.h"
#include "../naglowkowe/KreatorOrganizmow.h"
#include <algorithm>
#include <conio.h>
#include "../naglowkowe/Czlowiek.h"
#include <string>
#include <fstream>

#define ESC 27
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ARROW -32
#define SPACE 32

#define ZAPELNIENIE_SWIATA 20	// %

using namespace std;

string Swiat::komunikat = "";

Swiat::Swiat(int x, int y)
{
	this->x = x;
	this->y = y;
	this->koniec = 0;
	this->tura = 0;
	this->nastTura = 0;
	this->organizmy.reserve(x * y / 4);	// rezerwujemy miejsce na organizmy w tablicy
	this->StworzPlansze(x, y);	
	this->czlowiek = nullptr;
	this->WypelnijSwiat();
}
Swiat::Swiat()
{
	this->x = 0;
	this->y = 0;
	this->koniec = 0;
	this->tura = 0;
	this->nastTura = 0;
	this->organizmy.reserve(0);
	this->czlowiek = nullptr;
	this->plansza = nullptr;
}
Swiat::~Swiat() 
{
	for (int i = 0; i < x; i++)
	{
		delete[] plansza[i];
	}
	delete plansza;

	for (int i = 0; i < organizmy.size(); i++)
	{
		delete organizmy[i];
	}
}

void Swiat::Input()
{
	nastTura = false;
	while (!nastTura)
	{
		char znak = _getch();

		if (znak == ARROW)
		{
			if (this->czlowiek != nullptr)
			{
				this->czlowiek->SetNastepnyRuch(BRAK);
				znak = _getch();
				if (znak == LEFT)
				{
					this->czlowiek->SetNastepnyRuch(LEWO);
				}
				else if (znak == UP)
				{
					this->czlowiek->SetNastepnyRuch(GORA);
				}
				else if (znak == DOWN)
				{
					this->czlowiek->SetNastepnyRuch(DOL);
				}
				else if (znak == RIGHT)
				{
					this->czlowiek->SetNastepnyRuch(PRAWO);
				}
			}
			else 
			{
				_getch();
			}
			this->nastTura = true;
		}
		else if ((znak == 'u' || znak == 'U') && (this->czlowiek != nullptr))
		{
			this->czlowiek->WlaczUmiejetnosc();
		}
		else if (znak == ESC)
		{
			this->SetKoniec();
			this->nastTura = 1;
		}
		else if (znak == 'z')
		{
			this->ZapiszDoPliku();
		}
		else if (znak == SPACE)
		{
			this->nastTura = true;
		}
	}
}

void Swiat::RysujSwiat() 
{
	cout << "Autor: Marcel Zielinski - 191005\n";
	cout << "poruszanie - strzalki, zapis - z, umiejetnosc - u, nastepna tura - spacja\n\n";

	for (int i = 0; i < this->y; i++) 
	{
		for (int j = 0; j < this->x; j++) 
		{
			cout << " ";
			if ((plansza[j][i]) != nullptr) 
			{
				plansza[j][i]->Rysowanie();
			}
			else
			{
				cout << "_";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}

void Swiat::DodajOrganizm(Organizm * organizm) 
{
	if (this->organizmy.size() < (this->x * this->y)) 
	{
		this->organizmy.push_back(organizm);
		Punkt polozenie = organizm->GetPolozenie();
		this->plansza[polozenie.GetX()][polozenie.GetY()] = organizm;
	}
}
void Swiat::UsunOrganizm(Organizm* organizm)
{
	Punkt polozenie = organizm->GetPolozenie();
	this->plansza[polozenie.GetX()][polozenie.GetY()] = nullptr;

	if (organizm->GetTyp() == Organizm::TypOrganizmu::CZLOWIEK) {	this->czlowiek = nullptr;	}

	for (int i = 0; i < organizmy.size(); i++) 
	{
		if (organizmy[i] == organizm) 
		{
			organizmy[i]->Zabij();
			break;
		}
	}
}
void Swiat::CzyscWektor() 
{
	int i = 0;
	while (true)
	{
		if (i >= this->organizmy.size()) 
		{
			break;
		}
		if (organizmy[i]->GetZyje() == false)
		{	
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
			i--;
		}
		i++;
	}
}
void Swiat::WykonajTure()
{
		this->DodajTekst("Numer tury: " + to_string(this->tura));

		if (this->czlowiek != nullptr && this->czlowiek->CzyUmiejetnoscAktywna()) 
		{
			this->DodajTekst("Umiejetnosc czlowieka aktywna");
		} else 
		if (this->czlowiek == nullptr)
		{
			this->DodajTekst("Czlowiek nie zyje");
		}

		this->SortujOrganizmy();

		int i = 0;
		while (true) 
		{
			if (i >= organizmy.size())
			{
				break;
			}
			if (organizmy[i]->GetZyje() == 1 && organizmy[i]->GetTuraUrodzenia() != this->tura)
			{
				organizmy[i]->Akcja();
			}
			i++;
		}

		this->RysujSwiat();
		this->WyswietlKomunikat();
		this->CzyscTekst();	
		this->tura++;
		this->CzyscWektor();
}

bool Swiat::PorownajOrganizmy(Organizm * o1,  Organizm * o2)
{
	if (o1->GetInicjatywa() > o2->GetInicjatywa()) 
	{
		return true;
	}
	else if (o1->GetInicjatywa() < o2->GetInicjatywa()) 
	{
		return false;
	}
	else if (o1->GetTuraUrodzenia() < o2->GetTuraUrodzenia()) 
	{
		return true;
	}
	else return false;
}
void Swiat::SortujOrganizmy()
{
	sort(this->organizmy.begin(), this->organizmy.end(), PorownajOrganizmy);
}

Swiat::Kierunek Swiat::LosujKierunek()
{
	int numer = rand() % 4;

	if (numer == 0)
	{
		return Swiat::GORA;
	}
	else if (numer == 1)
	{
		return Swiat::PRAWO;
	}
	else if (numer == 2)
	{
		return Swiat::DOL;
	}
	else if (numer == 3)
	{
		return Swiat::LEWO;
	}
	else return Swiat::BRAK;
}
Punkt Swiat::LosujWolnePole()
{	
	bool miejsce = false;
	// sprawdzamy czy sa wolne pola
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (plansza[i][j] == nullptr) {
				miejsce = true;
				break;
			}
		}
	}

	if (miejsce) 
	{
		while (true) 
		{
			int t_x = rand() % x;
			int t_y = rand() % y;

			if (plansza[t_x][t_y] == nullptr)
			{
				return Punkt(t_x, t_y);
			}
		}
	}
	else {
		return Punkt(-1, 0);
	}
}
Punkt Swiat::LosujPoleObok(Punkt polozenie , int zasieg)
{
	int pole = rand() % 4;

	for (int i = 0; i < zasieg; i++)
	{
		if (pole == Swiat::Kierunek::LEWO
			&& polozenie.GetX() >= 0 + zasieg)
		{
			return Punkt(polozenie.GetX() - zasieg, polozenie.GetY());
		}
		else if (pole == Swiat::Kierunek::PRAWO
			&& polozenie.GetX() < this->x - zasieg)
		{
			return Punkt(polozenie.GetX() + zasieg, polozenie.GetY());
		}
		else if (pole == Swiat::Kierunek::GORA
			&& polozenie.GetY() >= 0 + zasieg)
		{
			return Punkt(polozenie.GetX(), polozenie.GetY() - zasieg);
		}
		else if (pole == Swiat::Kierunek::DOL
			&& polozenie.GetY() < this->y - zasieg)
		{
			return Punkt(polozenie.GetX(), polozenie.GetY() + zasieg);
		}
		zasieg--;
	}
	return polozenie;
}
Punkt Swiat::LosujWolnePoleObok(Punkt polozenie, int zasieg)
{
	int pole = rand() % 4;	// jezeli losowe pole bedzie zajete to juz lecimy po kolei

	for (int i = 0; i < zasieg; i++)
	{
		if (pole == Swiat::Kierunek::LEWO
			&& polozenie.GetX() >= 0 + zasieg
			&& this->plansza[polozenie.GetX() - zasieg][polozenie.GetY()] == nullptr)
		{
			return Punkt(polozenie.GetX() - zasieg, polozenie.GetY());
		} 
		else if (pole == Swiat::Kierunek::PRAWO
			&& polozenie.GetX() < this->x - zasieg 
			&& this->plansza[polozenie.GetX() + zasieg][polozenie.GetY()] == nullptr)
		{
			return Punkt(polozenie.GetX() + zasieg, polozenie.GetY());
		}
		else if (pole == Swiat::Kierunek::GORA
			&& polozenie.GetY() >= 0 + zasieg
			&& this->plansza[polozenie.GetX()][polozenie.GetY() - zasieg] == nullptr)
		{
			return Punkt(polozenie.GetX(), polozenie.GetY() - zasieg);
		}
		else if (pole == Swiat::Kierunek::DOL
			&& polozenie.GetY() < this->y - zasieg
			&& this->plansza[polozenie.GetX()][polozenie.GetY() + zasieg] == nullptr)
		{
			return Punkt(polozenie.GetX(), polozenie.GetY() + zasieg);
		}
		zasieg--;
	}
	return polozenie;
}
bool Swiat::CzyPozaPlansza(Punkt polozenie)	
{
	if (polozenie.GetX() < 0 
		|| polozenie.GetX() >= this->x
		|| polozenie.GetY() < 0 
		|| polozenie.GetY() >= this->y) 
	{
		return true;
	}
	else return false;
}

Swiat* Swiat::WczytajZPliku()
{
	ifstream in;
	string sciezka;
	cout << "Podaj nazwe zapisu: ";
	cin >> sciezka;
	sciezka += ".txt";
	in.open(sciezka);

	if (!in.is_open())
	{
		cout << "\nBlad otwarcia pliku!\n";
	}
	else
	{
		int typOrganizmu;
		int liczba;
		int x, y;
		in >> x >> y;
		Swiat* nowySwiat = new Swiat();
		nowySwiat->x = x;
		nowySwiat->y = y;
		nowySwiat->StworzPlansze(x, y);
		nowySwiat->organizmy.reserve(nowySwiat->x * nowySwiat->y / 2);

		in >> liczba;
		nowySwiat->tura = liczba;
		nowySwiat->czlowiek = nullptr;

		Organizm* organizm;

		while (!in.eof())
		{
			in >> typOrganizmu;
			in >> x >> y;
			organizm = KreatorOrganizmow::StworzNowyOrganizm((Organizm::TypOrganizmu)typOrganizmu, Punkt(x, y), nowySwiat);
			in >> liczba;
			organizm->SetSila(liczba);
			in >> liczba;
			organizm->SetTuraUrodzenia(liczba);
			if (typOrganizmu == Organizm::TypOrganizmu::CZLOWIEK)
			{
				nowySwiat->czlowiek = (Czlowiek*)organizm;
			}
			nowySwiat->DodajOrganizm(organizm);
		}
		return nowySwiat;
	}	
}
void Swiat::ZapiszDoPliku()
{
	ofstream zapis;
	string sciezka;
	cout << "Nazwa pliku : \n";
	cin >> sciezka;
	sciezka += ".txt";

	zapis.open(sciezka, ofstream::app);
	if (!zapis.is_open())
	{
		cout << "Blad tworzenia pliku";
		_getch();
	}
	else
	{
		zapis << x << " " << y << " ";
		zapis << this->tura << "\n";

		for (int i = 0; i < organizmy.size(); i++)
		{
			zapis << (int)organizmy[i]->GetTyp() << " ";
			zapis << organizmy[i]->GetPolozenie().GetX() << " ";
			zapis << organizmy[i]->GetPolozenie().GetY() << " ";
			zapis << organizmy[i]->GetSila() << " ";
			zapis << organizmy[i]->GetTuraUrodzenia() << " ";
		}
		zapis << "\n";
	}
	zapis.close();
	cout << "zapisano\n";
	_getch();
}

void Swiat::StworzPlansze(int x, int y)
{
	this->plansza = new Organizm ** [x];
	for (int i = 0; i < x; i++)
	{
		plansza[i] = new Organizm * [y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			plansza[i][j] = nullptr;
		}
	}
}
void Swiat::WypelnijSwiat()
{
	int rozmiarPlanszy = this->x * this->y;
	Punkt pole = this->LosujWolnePole();
	Organizm* tmpOrganizm = KreatorOrganizmow::StworzNowyOrganizm(Organizm::CZLOWIEK, pole, this);
	this->DodajOrganizm(tmpOrganizm);
	this->czlowiek = (Czlowiek*)tmpOrganizm;

	for (int i = 0; i < rozmiarPlanszy * ( ZAPELNIENIE_SWIATA / (double)100); i++) 
	{
		Organizm::TypOrganizmu typ = Organizm::LosujTyp();
		Punkt pole = this->LosujWolnePole();
		this->DodajOrganizm(KreatorOrganizmow::StworzNowyOrganizm(typ, pole, this));
	}
}

int Swiat::GetX()
{
	return x;
}
int Swiat::GetY()
{
	return y;
}
int Swiat::GetTura()
{
	return tura;
}
bool Swiat::GetKoniec()
{
	return this->koniec;
}

bool Swiat::GetCzlowiekZyje()
{
	if (this->czlowiek != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector<Organizm*> Swiat::GetOrganizmy()
{
	return this->organizmy;
}
Organizm* Swiat::GetCzlowiek()
{
	return (Organizm*)this->czlowiek;
}
Organizm*** Swiat::GetPlansza()
{
	return this->plansza;
}
void Swiat::SetPlansza(int x, int y, Organizm * pointer) 
{
	this->plansza[x][y] = pointer;
}
void Swiat::SetKoniec()
{
	this->koniec = 1;
}

void Swiat::DodajTekst(string tekst)
{
	this->komunikat += tekst += "\n";
}
void Swiat::CzyscTekst()
{
	this->komunikat = "";
}
void Swiat::WyswietlKomunikat()
{
	std::cout << this->komunikat << "\n";
}

void Swiat::WypiszOrganizmy()
{
	for (int i = 0; i < this->organizmy.size(); i++)
	{
		cout <<
			"\nTyp organizmu: " << this->organizmy[i]->GetTyp() <<
			" inicjatywa: " << this->organizmy[i]->GetInicjatywa() <<
			" tura urodzenia: " << this->organizmy[i]->GetTuraUrodzenia()
			<< "\n";
	}
}