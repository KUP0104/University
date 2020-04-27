#include "Ucet.h"

class Partner : public Ucet
{
private:
	Klient* partner;

public:
	Partner(int cislo_u, Klient* v, Klient* p);
	Partner(int cislo_u, Klient* v, Klient* p, double u);
	~Partner();

	Klient* GetPartner();
};

