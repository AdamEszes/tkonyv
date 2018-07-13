#include "stdafx.h"
#include <iostream>
using namespace std;

class szemely {
private:
	char nev[24];
	char cim[40];
	char munkszam[14];
	char otthszam[14];
public:
	szemely(char nev[] = "Nincs megadva", char cim[] = "Nincs megadva", char munkszam[] = "Nincs megadva", char otthszam[] = "Nincs megadva")
	{
		setadat(nev, 0);
		setadat(cim, 1);
		setadat(munkszam, 2);
		setadat(otthszam, 3);
	
	};

	char* getadat(int adatid = 0) {
		switch (adatid) {
		case 0:
			return nev;
		case 1:
			return cim;
		case 2:
			return munkszam;
		case 3:
			return otthszam;
		default:
			return nev;

		}
	}

	void setadat(char* adat, int adatid = 0){
		switch (adatid) {
		case 0:
			strcpy_s(nev,adat);
		case 1:
			strcpy_s(cim, adat);
		case 2:
			strcpy_s(munkszam, adat);
		case 3:
			strcpy_s(otthszam, adat);
		default:
			strcpy_s(nev, adat);

		}
	}

	void operator=(szemely bem) {
		strcpy_s(nev, bem.nev);
		strcpy_s(cim, bem.nev);
		strcpy_s(munkszam, bem.nev);
		strcpy_s(otthszam, bem.nev);
	}
};

class telefonk {
private:
	szemely * emberek;
	int hossz;
public:

	telefonk(int hossz = 0) {
		this->hossz = hossz;
		emberek = new szemely[hossz];
	}

	szemely getAt(int sorsz) {
		return(emberek[sorsz]);
	}

	void add(szemely & bem) {
		hossz++;
		emberek[hossz] = bem;


		//szemely* temp = new szemely[hossz];
		/*for (int i = 0; i < hossz-1; i++) {
			temp[i] = getAt(i);
		}
		
		temp[hossz] = bem;
		for (int i = 0; i < hossz; i++) {
			emberek[i] = temp[i];
		}*/
		
	}

	int gethossz() {
		return hossz;
	}

	void rem(int i) {
		for (int j = i; j < hossz - 1; j++) {
			emberek[j] = emberek[j + 1];
		}
		delete &emberek[hossz - 1];
	}

	
};

ostream &operator<<(ostream& ki, telefonk& k) {
	for (int i = 0; i < k.gethossz(); i++) {
		for (int j = 0; j < 4; j++) {
			ki << k.getAt(i).getadat(j) << endl;
		}
	}
	return ki;
}

void hozzaad(telefonk & telef) {
	cout << "Nev hozzáadása\nKerem a nevet:\n";
	char* adat = new char[40];
	cin >> adat;
	szemely temp = szemely(adat);
	cout << "Cim vagy -";
	cin >> adat;
	if (adat != "-") {
		temp.setadat(adat, 1);
	}
	cout << "Munkahelyi szam vagy -";
	cin >> adat;
	if (adat != "-") {
		temp.setadat(adat, 2);
	}
	cout << "Otthoni szam vagy -";
	cin >> adat;
	if (adat != "-") {
		temp.setadat(adat, 3);
	}
	telef.add(temp);



}

int main()
{
	telefonk alap;
	cout << "Telefonkönyv";
	while (true)
	{
		char bem;
		cin >> bem;
		switch (bem) {		//a menü helye
		case '1':
			hozzaad(alap);
			cout << alap;
			break;
		}
	}
	


	return 0;
}

