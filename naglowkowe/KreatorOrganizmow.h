#pragma once

#include "Organizm.h"

class KreatorOrganizmow
{
public:
	static Organizm* StworzNowyOrganizm(Organizm::TypOrganizmu typ, Punkt pozycja, Swiat* swiat);
};