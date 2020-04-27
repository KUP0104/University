#include "Klient.h"

class Ucet
{
private:
	static int pocet_uctu;
	static int pojistka;
	int cislo_uctu;
	double stav_uctu;
	double urok = 0;

	Klient* vlastnik;

public:
	Ucet(int cislo_u, Klient* v);
	Ucet(int cislo_u, Klient* v, double u);
	~Ucet();

	int GetCislo_uctu();
	double GetStav_uctu();
	double GetUrok();
	Klient* GetVlastnik();

	bool Muzu_vybrat(double suma);

	void Vlozit(double suma);
	bool Vybrat(double suma);
	void Zurocit();

	static int GetPocetUctu();
	static int GetPojistka();
	static void SetPojistka(int castka);
};

