#include "Klient.h"


int Klient::pocet_klientu = 0;

Klient::Klient(string j, int k)
{
	jmeno = j;
	kod = k;
	Klient::pocet_klientu += 1;
}

Klient::~Klient()
{
	Klient::pocet_klientu -= 1;
}


int Klient::GetPocetKlientu()
{
	return Klient::pocet_klientu;
}


int Klient::GetKod()
{
	return kod;
}

string Klient::GetJmeno()
{
	return jmeno;
}
