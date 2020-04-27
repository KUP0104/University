#include "Ucet.h"



int Ucet::pocet_uctu = 0;

int Ucet::pojistka = 1500;


Ucet::Ucet(int cislo_u, Klient* v)
{
	cislo_uctu = cislo_u;
	vlastnik = v;
	stav_uctu = 1000;
	Ucet::pocet_uctu += 1;
}

Ucet::Ucet(int cislo_u, Klient* v, double u)
{
	cislo_uctu = cislo_u;
	vlastnik = v;
	urok = u;
	stav_uctu = 0;
	Ucet::pocet_uctu += 1;
}

Ucet::~Ucet()
{
	Ucet::pocet_uctu -= 1;
}



int Ucet::GetPocetUctu()
{
	return Ucet::pocet_uctu;
}

int Ucet::GetPojistka()
{
	return Ucet::pojistka;
}

void Ucet::SetPojistka(int castka)
{
	Ucet::pojistka = castka;
}


int Ucet::GetCislo_uctu()
{
	return cislo_uctu;
}

double Ucet::GetStav_uctu()
{
	return stav_uctu;
}

double Ucet::GetUrok()
{
	return urok;
}

Klient* Ucet::GetVlastnik()
{
	return vlastnik;
}

bool Ucet::Muzu_vybrat(double suma)
{
	if (suma <= stav_uctu)
		return true;
	else return false;
}

void Ucet::Vlozit(double suma)
{
	stav_uctu += suma;
}

bool Ucet::Vybrat(double suma)
{
	if (Muzu_vybrat(suma))
	{
		stav_uctu -= suma;
		return true;
	}
	else return false;
}

void Ucet::Zurocit()
{
	stav_uctu = stav_uctu * (1 + urok);
}