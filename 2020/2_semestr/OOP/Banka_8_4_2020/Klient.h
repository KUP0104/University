#include <string>

using namespace std;

class Klient
{
private:
	static int pocet_klientu;
	int kod;
	string jmeno = "";


public:
	Klient(string j, int k);
	~Klient();

	int GetKod();
	string GetJmeno();

	static int GetPocetKlientu();
};

