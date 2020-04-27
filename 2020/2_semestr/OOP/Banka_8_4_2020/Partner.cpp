#include "Partner.h"


Partner::Partner(int cislo_u, Klient* v, Klient* p) : Ucet(cislo_u, v)
{
	this->partner = p;
}

Partner::Partner(int cislo_u, Klient* v, Klient* p, double u) : Ucet(cislo_u, v, u)
{
	this->partner = p;
}

Klient* Partner::GetPartner()
{
	return partner;
}
