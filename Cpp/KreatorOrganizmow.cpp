#include "../naglowkowe/KreatorOrganizmow.h"
#include "../naglowkowe/Organizm.h"
#include "../naglowkowe/Czlowiek.h"

#include "../naglowkowe/Zolw.h"
#include "../naglowkowe/Wilk.h"
#include "../naglowkowe/Owca.h"
#include "../naglowkowe/Lis.h"
#include "../naglowkowe/Antylopa.h"

#include "../naglowkowe/Trawa.h"
#include "../naglowkowe/Mlecz.h"
#include "../naglowkowe/Guarana.h"
#include "../naglowkowe/WilczeJagody.h"
#include "../naglowkowe/BarszczSosnowskiego.h"

Organizm* KreatorOrganizmow::StworzNowyOrganizm(Organizm::TypOrganizmu typ,
	Punkt pozycja, Swiat* swiat)
{
	if (typ == Organizm::TypOrganizmu::CZLOWIEK) { return new Czlowiek(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::WILK) { return new Wilk(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::OWCA) { return new Owca(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::LIS) { return new Lis(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::ZOLW) { return new Zolw(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::ANTYLOPA) { return new Antylopa(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::TRAWA) { return new Trawa(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::MLECZ) { return new Mlecz(swiat, pozycja); }
	
	else if (typ == Organizm::TypOrganizmu::GUARANA) { return new Guarana(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::WILCZE_JAGODY) { return new WilczeJagody(swiat, pozycja); }
	else if (typ == Organizm::TypOrganizmu::BARSZCZ_SOSNOWSKIEGO) { return new BarszczSosnowskiego(swiat, pozycja); }
	else return nullptr;
}