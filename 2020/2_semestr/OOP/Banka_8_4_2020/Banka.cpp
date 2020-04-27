#include <iostream>
#include "Banka.h"
#include "stdlib.h"



Banka::Banka(int k, int u)
{	
	pocetKlientu = k;
	klienti = (Klient**)malloc(k * sizeof(Klient*));
	for (int i = 0; i < k; i++)
		klienti[i] = (Klient*)malloc(sizeof(Klient));

	pocetUctu = u;
	ucty = (Ucet**)malloc(u * sizeof(Ucet*));
	for (int j = 0; j < u; j++)
		ucty[j] = (Ucet*)malloc(sizeof(Ucet));

	pucty = (Partner **)malloc(u * sizeof(Partner *));
	for (int l = 0; l < u; l++)
		pucty[l] = (Partner *)malloc(sizeof(Partner));

	//	Dynamicka verze pro nacitani i z databaze
	/*
	skutecneKlientu = 0;
	skutecneUctu = 0;
	*/
}

Banka::~Banka()
{

}

Klient* Banka::GetKlient(int k)
{
	Klient* klient;

	if(k == klienti[k]->GetKod())
		klient = klienti[k];

	return klient;
}

Ucet* Banka::GetUcet(int u)
{
	Ucet* ucet;

	if(u == ucty[u]->GetCislo_uctu())
		ucet = ucty[u];

	return ucet;
}

Partner* Banka::GetPucet(int u)
{
	Partner *ucet;

	if (u == pucty[u]->GetCislo_uctu())
		ucet = pucty[u];

	return ucet;
}

int Banka::GetPojisteni()
{
	return Ucet::GetPojistka();
}

void Banka::SetPojisteni(int castka)
{
	Ucet::SetPojistka(castka);
}

int Banka::Klientu()
{
	//	Dynamicka verze pro nacitani i z databaze
	/*
	skutecneKlientu = 0;

	for(int i = 0; i < pocetKlientu; i++)
	{
		if(sizeof(klienti[i]) == sizeof(Klient*) && klienti[i]->GetJmeno() != "")
			skutecneKlientu++;
	}

	return skutecneKlientu;
	*/

	return Klient::GetPocetKlientu();
}

int Banka::Uctu()
{
	//	Dynamicka verze pro nacitani i z databaze
	/*
	skutecneUctu = 0;

	for(int i = 0; i < pocetUctu; i++)
	{
		if(sizeof(ucty[i]) == sizeof(Ucet*) && ucty[i]->GetVlastnik() != NULL)
			skutecneUctu++;
	}
	
	return skutecneUctu;
	*/

	return Ucet::GetPocetUctu();
}

Klient* Banka::CreateKlient(int k, string j)
{
	Klient* klient = new Klient(j, k);

	klienti[k] = klient;

	return klient;
}

Ucet* Banka::CreateUcet(int cislo_u, Klient* k)
{
	Ucet* ucet = new Ucet(cislo_u, k);

	ucty[cislo_u] = ucet;

	return ucet;
}

Ucet* Banka::CreateUcet(int cislo_u, Klient* k, double ir)
{
	Ucet* ucet = new Ucet(cislo_u, k, ir);
	
	ucty[cislo_u] = ucet;
	
	return ucet;
}

Partner* Banka::CreateUcet(int cislo_u, Klient* k, Klient *p)
{
	Partner* ucet = new Partner(cislo_u, k, p);
	
	pucty[cislo_u] = ucet;

	return ucet;
}

Partner* Banka::CreateUcet(int cislo_u, Klient* k, Klient *p, double ir)
{
	Partner* ucet = new Partner(cislo_u, k, p, ir);
	
	pucty[cislo_u] = ucet;
	
	return ucet;
}

void Banka::Zuroc()
{
	for (int i = 0; i < pocetUctu; i++)
	{
		if(ucty[i]->GetUrok() > 0)
			ucty[i]->Zurocit();
	}
	
	return;
}