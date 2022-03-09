#include <iostream>
using namespace std;

//Z0.1
char* AlocirajIKopiraj(const char* tekst) {
	if (tekst == nullptr)
		return nullptr;
	int vel = strlen(tekst) + 1;
	char* temp = new char[vel];
	strcpy_s(temp, vel, tekst);
	return temp;
}

struct Datum
{
	int* _dan = nullptr;
	int* _mjesec = nullptr;
	int* _godina = nullptr;
	//Z1.1
	void Unos(int d, int m, int g) {
		if (_dan == nullptr)
			_dan = new int;
		*_dan = d;

		if (_mjesec == nullptr)
			_mjesec = new int;
		*_mjesec = m;

		if (_godina == nullptr)
			_godina = new int;
		*_godina = g;
	}

	//Z1.2
	void Unos(Datum& datum) {
		if (_dan == nullptr)
			_dan = new int;
		*_dan = *datum._dan;

		if (_mjesec == nullptr)
			_mjesec = new int;
		*_mjesec = *datum._mjesec;

		if (_godina == nullptr)
			_godina = new int;
		*_godina = *datum._godina;
	}
	//Z1.3
	void Unos(Datum* datum) {
		if (_dan == nullptr)
			_dan = new int;
		*_dan = *datum->_dan;

		if (_mjesec == nullptr)
			_mjesec = new int;
		*_mjesec = *datum->_mjesec;

		if (_godina == nullptr)
			_godina = new int;
		*_godina = *datum->_godina;
	}
	//Z1.4
	int GetDan() { return *_dan; }
	int GetMjesec() { return *_mjesec; }
	int GetGodina() { return *_godina; }
	//Z1.5
	void SetDan(int dan) {
		if (_dan == nullptr)
			_dan = new int;
		*_dan = dan;
	}
	//Z1.6
	void SetMjesec(int mjesec) {
		if (_mjesec == nullptr)
			_mjesec = new int;
		*_mjesec = mjesec;
	}
	//Z1.7
	void SetGodina(int godina) {
		if (_godina == nullptr)
			_godina = new int;
		*_godina = godina;
	}
	//Z1.8
	void Ispis() {
		cout << *_dan << "." << *_mjesec << "." << *_godina << endl;
	}
	//Z1.9
	void Dealokacija() {
		delete _dan; _dan = nullptr;
		delete _mjesec; _mjesec = nullptr;
		delete _godina; _godina = nullptr;
	}
	int ToInt() {
		int temp = *_dan + *_mjesec * 12 + *_godina * 365;
		return temp;
	}
};
//Z1.10
bool JeLiIsti(Datum& d1, Datum& d2) {
	return d1.ToInt() == d2.ToInt();
}
//Z1.11
Datum& GetStarijiDatum(Datum& d1, Datum& d2) {
	if (d1.ToInt() > d2.ToInt())
		return d2;
	return d1;
}
//Z1.12
Datum& GetNovijiDatum(Datum& d1, Datum& d2) {
	if (d1.ToInt() > d2.ToInt())
		return d1;
	return d2;
}
//Z1.13
Datum* GetNajstarijiDatum(Datum datum[], int size) {
	Datum* temp = &datum[0];
	for (int i = 1; i < size; i++)
	{
		if (temp->ToInt() > datum[i].ToInt())
			temp = &datum[i];
	}
	return temp;
}
//Z1.14
Datum* GetNajnovijiDatum(Datum datum[], int size) {
	Datum* temp = &datum[0];
	for (int i = 1; i < size; i++)
	{
		if (temp->ToInt() < datum[i].ToInt())
			temp = &datum[i];
	}
	return temp;
}

struct Glumac {
	char _jmbg[14] = "";
	char* _ime = nullptr;
	char* _prezime = nullptr;
	Datum* _datumRodjenja = nullptr;
	char* _mjestoRodjenja = nullptr;
	char _drzava[100];
	bool _spol; //1:Muski, 0:Zenski
	//Z2.1
	void Unos(const char* jmbg, const char* ime, const char* prezime, Datum& datumRodjenja,	const char* mjestoRodjenja, const char* drzava, bool spol) {
		strcpy_s(_jmbg, 14, jmbg);
		_ime = AlocirajIKopiraj(ime);
		_prezime = AlocirajIKopiraj(prezime);
		_datumRodjenja = new Datum;					// da li je potrebno alocirati prostor za objekt _datumRodjenja ili to radi funkcija ispod
		_datumRodjenja->Unos(datumRodjenja);
		_mjestoRodjenja = AlocirajIKopiraj(mjestoRodjenja);
		strcpy_s(_drzava, 100, drzava);
		_spol = spol;
	}
	//Z2.2
	void Unos(Glumac& glumac) {
		strcpy_s(_jmbg, 14, glumac._jmbg);
		_ime = AlocirajIKopiraj(glumac._ime);
		_prezime = AlocirajIKopiraj(glumac._prezime);
		_datumRodjenja = new Datum;
		//_datumRodjenja->Unos(*glumac._datumRodjenja->_dan, *glumac._datumRodjenja->_mjesec, *glumac._datumRodjenja->_godina);
		_datumRodjenja->Unos(glumac._datumRodjenja);
		_mjestoRodjenja = AlocirajIKopiraj(glumac._mjestoRodjenja);
		strcpy_s(_drzava, 100, glumac._drzava);
		_spol = glumac._spol;
	}
	//Z2.3
	void SetJmbg(const char* jmbg) {
		strcpy_s(_jmbg, 14, jmbg);
	}
	//Z2.4
	void SetIme(const char* ime) {
		delete[] _ime;
		_ime = AlocirajIKopiraj(ime);
	}
	//Z2.5
	void SetPrezime(const char* prezime) {
		delete[] _prezime;
		_prezime = AlocirajIKopiraj(prezime);
	}
	//Z2.6
	void SetDatumRodjenja(Datum& datumRodjenja) {
		if (_datumRodjenja == nullptr)
			_datumRodjenja = new Datum;
		_datumRodjenja->Unos(datumRodjenja);

	}
	//Z2.7
	void SetMjestoRodjenja(const char* mjestoRodjenja) {
		delete[] _mjestoRodjenja;
		_mjestoRodjenja = AlocirajIKopiraj(mjestoRodjenja);
	}
	//Z2.8		
	void SetDrzava(const char* drzava) {
		strcpy_s(_drzava, 100, drzava);
	}
	//Z2.9
	void SetSpol(bool spol) {
		_spol = spol;
	}
	//Z2.10
	void Ispis() {
		cout << "Ime: " << _ime << endl;
		cout << "Prezime: " << _prezime << endl;
		cout << "JMBG: " << _jmbg << endl;
		cout << "Datum Rodjenja: "; _datumRodjenja->Ispis();
		cout << "Drzava: " << _drzava << endl;
		cout << "Spol: " << ((_spol == 1) ? "Muski" : "Zenski") << endl;


	}
	//Z2.11
	void Dealokacija() {
		delete[] _ime; _ime = nullptr;
		delete[] _prezime; _prezime = nullptr;
		delete[] _mjestoRodjenja; _mjestoRodjenja = nullptr;
		_datumRodjenja->Dealokacija();
		delete _datumRodjenja; _datumRodjenja = nullptr;
	}
};

struct Film {
	char _filmID[50] = ""; //prema ISAN standardu
	char* _naziv = nullptr;
	char _zanr[40];
	int _godinaIzlaska;
	int _trenutnoGlumaca = 0;
	Glumac _glumackaPostava[20];
	int _trenutnoOcjena = 0;
	int* _ocjene = nullptr; //Dinamicki prosirivati ovaj niz svakim novim dodavanjem
	//Z3.1
	void Unos(const char* filmID, const char* naziv, const char* zanr, int godinaIzlaska) {
		strcpy_s(_filmID, 50, filmID);
		_naziv = AlocirajIKopiraj(naziv);
		strcpy_s(_zanr, 40, zanr);
		_godinaIzlaska = godinaIzlaska;
		//_ocjene = new int[_trenutnoOcjena];						//treba li inicijalizirati ocjene
	}
	//Z3.2
	void Unos(Film& film) {
		strcpy_s(_filmID, 50, film._filmID);
		_naziv = AlocirajIKopiraj(film._naziv);
		strcpy_s(_zanr, 40, film._zanr);
		_godinaIzlaska = film._godinaIzlaska;
		_trenutnoOcjena = film._trenutnoOcjena;
		_ocjene = new int[_trenutnoOcjena];
		for (int i = 0; i < _trenutnoOcjena; i++)
		{
			_ocjene[i] = film._ocjene[i];
		}
		for (int i = 0; i < film._trenutnoGlumaca; i++) {
			_glumackaPostava[i].Unos(film._glumackaPostava[i]);
		}

	}
	//Z3.3
	bool DodajGlumca(Glumac& g) {
		if (_trenutnoGlumaca == 20)
			return false;
		_glumackaPostava[_trenutnoGlumaca].Unos(g);
		_trenutnoGlumaca++;
		return true;
	}
	//Z3.4
	bool DodajOcjenu(int ocjena) {
		if (ocjena < 1 || ocjena > 10)
			return false;

		int* temp = _ocjene;
		_ocjene = new int[_trenutnoOcjena + 1];
		for (int i = 0; i < _trenutnoOcjena; i++) {
			_ocjene[i] = temp[i];
		}
		delete[] temp;
		temp = nullptr;
		_ocjene[_trenutnoOcjena] = ocjena;
		_trenutnoOcjena++;
		return true;
	}
	//Z3.5
	void Ispis() {
		cout << "Naziv: " << _naziv << endl;
		cout << "Zanr: " << _zanr << endl;
		cout << "Godina izlaska: " << _godinaIzlaska << endl;
		cout << "Glumacka Postava: " << endl;
		for (int i = 0; i < _trenutnoGlumaca; i++) {
			_glumackaPostava[i].Ispis();
		}
		cout << "Ocjene: ";
		for (int i = 0; i < _trenutnoOcjena; i++)
		{
			cout << _ocjene[i];
			if (i != _trenutnoOcjena - 1)
				cout << ",";
			else
				cout << "." << endl;

		}
	}
	//Z3.6
	float GetProsjecnaOcjena() {
		if (_trenutnoOcjena == 0)
			return 0.0;
		float zbroj = 0.0;
		for (int i = 0; i < _trenutnoOcjena; i++) {
			zbroj += _ocjene[i];
		}
		return zbroj / _trenutnoOcjena;

	}
	//Z3.7
	void Dealokacija() {
		delete[] _naziv; _naziv = nullptr;
		delete[] _ocjene; _ocjene = nullptr;
	}
};

void Zadatak1() {
	cout << ":Zadatak 1:" << endl;
	Datum prviMart, danNezavisnosti, danDrzavnosti;
	prviMart.Unos(1, 3, 2021);
	danNezavisnosti.Unos(prviMart);
	danDrzavnosti.Unos(&prviMart);
	danDrzavnosti.SetDan(25);
	danDrzavnosti.SetMjesec(11);
	danDrzavnosti.SetGodina(2021);

	cout << "Dan nezavisnosti: " << endl;
	danNezavisnosti.Ispis();
	cout << endl << "Dan drzavnosti: " << endl;
	danDrzavnosti.Ispis();
	prviMart.Dealokacija();
	danNezavisnosti.Dealokacija();
	danDrzavnosti.Dealokacija();

	Datum danD, operacijaBarbarossa, sarajevskiAtentat, apolloSlijetanje, blackThursday;
	danD.Unos(6, 6, 1944);
	operacijaBarbarossa.Unos(22, 6, 1941);
	sarajevskiAtentat.Unos(28, 6, 1914);
	apolloSlijetanje.Unos(24, 7, 1969);
	blackThursday.Unos(24, 10, 1929);

	Datum historijskiDogadjaji[5];
	historijskiDogadjaji[0].Unos(danD);
	historijskiDogadjaji[1].Unos(operacijaBarbarossa);
	historijskiDogadjaji[2].Unos(sarajevskiAtentat);
	historijskiDogadjaji[3].Unos(apolloSlijetanje);
	historijskiDogadjaji[4].Unos(blackThursday);

	cout << endl << "Najstariji datum: " << endl;
	GetNajstarijiDatum(historijskiDogadjaji, 5)->Ispis();
	cout << endl << "Najnoviji datum: " << endl;
	GetNajnovijiDatum(historijskiDogadjaji, 5)->Ispis();

	//DEALOKACIJE
	danD.Dealokacija();
	operacijaBarbarossa.Dealokacija();
	sarajevskiAtentat.Dealokacija();
	apolloSlijetanje.Dealokacija();
	blackThursday.Dealokacija();
	for (size_t i = 0; i < 5; i++)
		historijskiDogadjaji[i].Dealokacija();
	cout << endl << "Dealokacija uspjesna!" << endl;
}

void Zadatak2() {
	cout << ":Zadatak 2:" << endl;

	Glumac alPacino, deNiro;
	Datum temp1, temp2;
	temp1.Unos(25, 4, 1940);
	temp2.Unos(17, 8, 1943);
	alPacino.Unos("1304996055555", "Alfredo", "Pacino", temp1, "Manhattan, NYC", "SAD", 1);
	deNiro.Unos(alPacino);
	deNiro.SetIme("Robert");
	deNiro.SetPrezime("De Niro");
	deNiro.SetDatumRodjenja(temp2);
	deNiro.SetMjestoRodjenja("Greenwich Village");
	deNiro.SetDrzava("SAD");
	deNiro.SetSpol(1);

	Datum datumi[5];
	datumi[0].Unos(7, 6, 1995);
	datumi[1].Unos(7, 11, 1991);
	datumi[2].Unos(3, 6, 1995);
	datumi[3].Unos(5, 6, 1992);
	datumi[4].Unos(1, 6, 1993);
	Glumac glumciNarodnogPozorista[5];
	glumciNarodnogPozorista[0].Unos("0706995088888", "Barb", "Dwyer", datumi[0], "Mostar", "BiH", 1);
	glumciNarodnogPozorista[1].Unos("0711991144488", "Anna", "Graham", datumi[1], "Ostrozac", "BiH", 0);
	glumciNarodnogPozorista[2].Unos("0306995099999", "Benjamin", "Button", datumi[2], "Sarajevo", "BiH", 1);
	glumciNarodnogPozorista[3].Unos("0506992011993", "Jack", "Pott", datumi[3], "Vogosca", "BiH", 1);
	glumciNarodnogPozorista[4].Unos("0106993094444", "Justin", "Case", datumi[4], "Kotor-Varos", "BiH", 1);

	cout << "Ispis svih glumaca:: " << endl;
	for (size_t i = 0; i < 5; i++) {
		cout << "-----------------------------------------------" << endl;
		glumciNarodnogPozorista[i].Ispis();
	}
	cout << "-----------------------------------------------" << endl;
	cout << endl;

	//DEALOKACIJE
	temp1.Dealokacija();
	temp2.Dealokacija();
	alPacino.Dealokacija();
	deNiro.Dealokacija();
	for (size_t i = 0; i < 5; i++) {
		datumi[i].Dealokacija();
		glumciNarodnogPozorista[i].Dealokacija();
	}
	cout << "Dealokacija uspjesna!" << endl;
}

void Zadatak3() {
	Datum temp1, temp2;
	temp1.Unos(25, 4, 1940);
	temp2.Unos(17, 8, 1943);
	Glumac alPacino, deNiro;
	alPacino.Unos("2504940555551", "Alfredo", "Pacino", temp1, "Manhattan, NYC", "SAD", 1);
	deNiro.Unos("1708943055555", "Robert", "De Niro", temp2, "NYC", "SAD", 1);

	Film irishman;
	irishman.Unos("XXXX-AAAA-BBBB-CCCC", "The Irishman", "Biografija, krimi, drama", 2019);
	irishman.DodajGlumca(alPacino);
	irishman.DodajGlumca(deNiro);
	irishman.DodajOcjenu(10);
	irishman.DodajOcjenu(8);
	irishman.DodajOcjenu(9);
	irishman.DodajOcjenu(8);
	irishman.DodajOcjenu(8);
	Film kopija;
	kopija.Unos(irishman);
	kopija.Ispis();
	//DEALOKACIJE
	irishman.Dealokacija();
	kopija.Dealokacija();
	alPacino.Dealokacija();
	deNiro.Dealokacija();
	temp1.Dealokacija();
	temp2.Dealokacija();
}

void Menu() {
	int nastaviDalje = 1;
	while (nastaviDalje == 1) {
		int izbor = 0;
		do {
			system("cls");
			cout << "::Zadaci::" << endl;
			cout << "(1) Zadatak 1" << endl;
			cout << "(2) Zadatak 2" << endl;
			cout << "(3) Zadatak 3" << endl;
			cout << "Unesite odgovarajuci broj zadatka za testiranje: -->: ";
			cin >> izbor;
			cout << endl;
		} while (izbor < 1 || izbor > 3);
		switch (izbor) {
		case 1: Zadatak1(); cout << "Done." << endl; break;
		case 2: Zadatak2(); cout << "Done." << endl; break;
		case 3: Zadatak3(); cout << "Done." << endl; break;
		default:break;
		}
		do {
			cout << "DA LI ZELITE NASTAVITI DALJE? (1/0): ";
			cin >> nastaviDalje;
		} while (nastaviDalje != 0 && nastaviDalje != 1);
	}
}

int main() {
	Menu();
	return 0;
}

