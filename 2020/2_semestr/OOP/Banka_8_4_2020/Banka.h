#include "Partner.h"

class Banka
{
private:

	Klient** klienti;
	int pocetKlientu;

	Ucet** ucty;
	int pocetUctu;

	Partner** pucty;
	int pocetPuctu;

	int skutecneKlientu;
	int skutecneUctu;
	int skutecnePuctu;

public:
	Banka(int k, int u);
	~Banka();

	Klient* GetKlient(int k);
	Ucet* GetUcet(int u);
	Partner* GetPucet(int u);
	int Klientu();
	int Uctu();
	int GetPojisteni();
	void SetPojisteni(int castka);

	Klient* CreateKlient(int k, string j);
	Ucet* CreateUcet(int cislo_u, Klient* k);
	Ucet* CreateUcet(int cislo_u, Klient* k, double ir);
	Partner* CreateUcet(int cislo_u, Klient* k, Klient *p);
	Partner* CreateUcet(int cislo_u, Klient* k, Klient *p, double ir);

	void Zuroc();
};

