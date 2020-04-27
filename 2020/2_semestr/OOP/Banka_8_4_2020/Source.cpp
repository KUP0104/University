#include <iostream>
#include <string>
#include "Banka.h"


using namespace std;


int main()
{
	int max_klientu = 20, max_uctu = 20;
	int volba_uzivatele;
	bool end = true;

	string jmeno;
	int osobni_cislo, osobni_cislo_partner, cislo_uctu, castka, pojistka;

	Banka* EquaBank = new Banka(max_klientu, max_uctu);	//	Vytvoření instance banky 

	//	Naplneni Equa banky 10 klienty
	for (int i = 0; i < 10; i++)
	{
		EquaBank->CreateKlient(i, "FANTOMAS");
		if(i % 2)
			EquaBank->CreateUcet(i, EquaBank->GetKlient(i), 0.5);
		else
			EquaBank->CreateUcet(i, EquaBank->GetKlient(i));
	}
	

	
	while (end)
	{
		cout << "Zvol pozadovanou ulohu:" << endl;
		cout << "\t1 - pridani klienta\n\t2 - pridani uctu\n\t3 - vklad\n\t4 - vyber\n\t5 - stav uctu\n\t6 - pripsani uroku\n\t7 - vyhledani uctu\n\t8 - vyhledani klienta\n\t9 - pocet klientu\n\t10 - pocet uctu\n\t11 - pojistka uctu\n\t12 - zmena pojistky uctu" << endl;
		cin >> volba_uzivatele;

		switch (volba_uzivatele)
		{
		case 1:	//	Pridani klienta
			cout << "Zadej jmeno klienta:" << endl;
			cin >> jmeno;
			EquaBank->CreateKlient(EquaBank->Klientu() + 1, jmeno);
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Uspesne pridany klient!" << endl;
			cout << "---------------------------------------------" << endl;
			break;
			
		case 2:	//	Pridani Uctu
			cout << "Zadej osobni cislo klienta:" << endl;
			cin >> osobni_cislo;
			cout << "Zadej osobni cislo partnera:" << endl;
			cin >> osobni_cislo_partner;
			cout << endl;
			cout << "---------------------------------------------" << endl;
			EquaBank->CreateUcet(EquaBank->Uctu() + 1, EquaBank->GetKlient(osobni_cislo), EquaBank->GetKlient(osobni_cislo_partner));
			cout << "Uspesne pridany ucet cislo " << EquaBank->Uctu() << "!" << endl;
			cout << "---------------------------------------------" << endl;
			break;
			
		case 3:	//	Vklad
			cout << "Zadej cislo uctu:" << endl;
			cin >> cislo_uctu;
			cout << "Zadej castku:" << endl;
			cin >> castka;
			EquaBank->GetUcet(cislo_uctu)->Vlozit(castka);
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Uspesne pridany peniz!" << endl;
			cout << "---------------------------------------------" << endl;
			break;
			
		case 4:	//	Vyber
			cout << "Zadej cislo uctu:" << endl;
			cin >> cislo_uctu;
			cout << "Zadej castku:" << endl;
			cin >> castka;
			cout << endl;
			cout << "---------------------------------------------" << endl;
			if(EquaBank->GetUcet(cislo_uctu)->Muzu_vybrat(castka))
			{
				EquaBank->GetUcet(cislo_uctu)->Vybrat(castka);
				cout << "Uspesne vybrany peniz!" << endl;
			}
			else
				cout << "Eror: nemuzes vybrat castku, nedostatek na ucte!" << endl;
			cout << "---------------------------------------------" << endl;
			break;
			
		case 5:	//	Stav uctu
			cout << "Zadej cislo uctu:" << endl;
			cin >> cislo_uctu;
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Stav uctu je: " << EquaBank->GetUcet(cislo_uctu)->GetStav_uctu() << endl;
			cout << "---------------------------------------------" << endl;
			break;
		
		case 6:	//	Pripsani uroku
			EquaBank->Zuroc();
			cout << endl << "Uspesne zuroceno!" << endl;
			break;
			
		case 7:	//	Vyhledani uctu
			cout << "Zadej cislo uctu:" << endl;
			cin >> cislo_uctu;
			cout << endl;
			cout << "---------------------------------------------" << endl;
			if(EquaBank->GetPucet(cislo_uctu)->GetCislo_uctu() != cislo_uctu)
			{
				cout << "Vlastnik uctu je: " << EquaBank->GetUcet(cislo_uctu)->GetVlastnik()->GetJmeno() << endl;
				cout << "Kod vlastnika uctu je: " << EquaBank->GetUcet(cislo_uctu)->GetVlastnik()->GetKod() << endl;
				cout << "Stav uctu je: " << EquaBank->GetUcet(cislo_uctu)->GetStav_uctu() << endl;
				cout << "Cislo uctu je: " << EquaBank->GetUcet(cislo_uctu)->GetCislo_uctu() << endl;
			}
			else
			{
				cout << "Vlastnik uctu je: " << EquaBank->GetPucet(cislo_uctu)->GetVlastnik()->GetJmeno() << endl;
				cout << "Kod vlastnika uctu je: " << EquaBank->GetPucet(cislo_uctu)->GetVlastnik()->GetKod() << endl;
				cout << "Partner uctu je: " << EquaBank->GetPucet(cislo_uctu)->GetPartner()->GetJmeno() << endl;
				cout << "Stav uctu je: " << EquaBank->GetPucet(cislo_uctu)->GetStav_uctu() << endl;
				cout << "Cislo uctu je: " << EquaBank->GetPucet(cislo_uctu)->GetCislo_uctu() << endl;
			}
			cout << "---------------------------------------------" << endl;
			break;
			
		case 8:	//	Vyhledani klienta
			cout << endl << "Zadej cislo klienta:" << endl;
			cin >> osobni_cislo;
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Jmeno klienta je: " << EquaBank->GetKlient(osobni_cislo)->GetJmeno() << endl;
			cout << "Osobní cislo klienta je: " << EquaBank->GetKlient(osobni_cislo)->GetKod() << endl;
			cout << "---------------------------------------------" << endl;
			break;
		
		case 9: //	Pocet klientu
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Pocet klientu je: " << EquaBank->Klientu() << endl;
			cout << "---------------------------------------------" << endl;
			break;

		case 10: //	Pocet uctu
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Pocet uctu je: " << EquaBank->Uctu() << endl;
			cout << "---------------------------------------------" << endl;
			break;

		case 11: //	Pojistka uctu
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Globalni vyse pojistky uctu je: " << EquaBank->GetPojisteni() << endl;
			cout << "---------------------------------------------" << endl;
			break;

		case 12: //	Zmena pojistky uctu
			cout << "Zadaj novou vysi pojistky" << endl;
			cin >> pojistka;
			EquaBank->SetPojisteni(pojistka);
			cout << endl;
			cout << "---------------------------------------------" << endl;
			cout << "Uspesne zmeneno pojisteni uctu!" << endl;
			cout << "---------------------------------------------" << endl;
			break;

		default:
			end = false;
			break;
		}

		//	Odradkovani
		cout << endl;
	}

	return 0;
}