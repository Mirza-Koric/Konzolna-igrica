#include <iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

enum class Elementi{VATRA,VODA,SNIJEG};
enum class Boje{RED,BLUE,YELLOW,GREEN,CYAN,PURPLE,BLANK};

void nacrtajIgraca()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 0 && j == 1)
				cout << "O";
			else if (i == 1 && j == 1)
				cout << "|";
			else if ((i == 1 || i == 2) && j == 0)
				cout << "/";
			else if ((i == 1 || i == 2) && j == 2)
				cout << "\\";
			else cout << " ";
		}
		cout << endl;
	}
}

class Karta {
private:
	int vrijednost;
	Elementi element;
	Boje boja;
public:
	Karta()
	{
		vrijednost = rand() % 11 + 2;

		int elementTemp= rand() % 3;

		switch (elementTemp)
		{
		case 0: element = Elementi::VATRA; break;
		case 1: element = Elementi::VODA; break;
		case 2: element = Elementi::SNIJEG; break;
		}

		int bojaTemp= rand() % 6;

		switch (bojaTemp)
		{
		case 0: boja = Boje::RED; break;
		case 1: boja = Boje::BLUE; break;
		case 2: boja = Boje::YELLOW; break;
		case 3: boja = Boje::GREEN; break;
		case 4: boja = Boje::CYAN; break;
		case 5: boja = Boje::PURPLE; break;
		}
	}

	int getVrijednost()const { return vrijednost; }
	Elementi getElement() const { return element; }
	Boje getBoja()const { return boja; }

	_declspec(property(get = getVrijednost)) int Vrijednost;
	_declspec(property(get = getElement)) Elementi Element;
	_declspec(property(get = getBoja)) Boje Boja;

	~Karta() {};

};

ostream& operator<<(ostream& COUT, const Karta& obj)
{
	switch (obj.Boja)
	{
	case Boje::RED:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;
	case Boje::BLUE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

		break;
	case Boje::YELLOW:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

		break;
	case Boje::GREEN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		break;
	case Boje::CYAN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		break;
	case Boje::PURPLE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		break;
	}

	COUT << "+----------+" << endl;
	COUT << "|          |" << endl;

	switch (obj.Element)
	{
	case Elementi::VATRA:
		COUT << "|  VATRA   |" << endl;
		break;
	case Elementi::VODA:
		COUT << "|  VODA    |" << endl;
		break;
	case Elementi::SNIJEG:
		COUT << "|  SNIJEG  |" << endl;
		break;
	}

	if (obj.Vrijednost < 10)

		COUT << "|    " << obj.Vrijednost << "     |" << endl;		//ova linija je zaustavljala program i bio je problem debugirati jer nisam dobio skoro nikakvih povratnih informacija
	else															//ali na kraju sam uspio, uz puno googlanja, saznati da se radilo o dinamickom alociranju niza od 0 elemenata
		COUT << "|    " << obj.Vrijednost << "    |" << endl;


	COUT << "|          |" << endl;
	COUT << "|          |" << endl;
	COUT << "|          |" << endl;

	COUT << "+----------+" << endl;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return COUT;
}
bool operator==(const Karta& k1, const Karta& k2)
{
	if (k1.Element == k2.Element && k1.Vrijednost == k2.Vrijednost)
			return true;
	return false;
}
bool operator!=(const Karta& k1, const Karta& k2)
{
	return !(k1 == k2);
}
bool operator>(const Karta& k1, const Karta& k2)
{
	if (k1.Element == Elementi::VATRA && k2.Element == Elementi::SNIJEG || k1.Element == Elementi::VODA && k2.Element == Elementi::VATRA || k1.Element == Elementi::SNIJEG && k2.Element == Elementi::VODA)
		return true;
	if (k1.Element == k2.Element)
	{
		if (k1.Vrijednost > k2.Vrijednost)
			return true;
	}
	return false;
}
bool operator>=(const Karta& k1, const Karta& k2)
{
	return (k1 == k2 || k1 > k2);
}

class Poen {
private:
	char izgled;
	Boje boja;
public:
	Poen() 
	{
		izgled = ' ';
		boja = Boje::BLANK;
	}

	Poen(Elementi elementKarte, Boje bojaKarte)
	{
		switch (elementKarte)
		{
		case Elementi::VATRA: izgled = 'F'; break;
		case Elementi::VODA: izgled = 'W'; break;
		case Elementi::SNIJEG: izgled = 'S'; break;
		}

		boja = bojaKarte;
	}


	char getIzgled()const { return izgled; }
	Boje getBoja()const { return boja; }

	_declspec(property(get = getIzgled)) char Izgled;
	_declspec(property(get = getBoja)) Boje Boja;

	Poen& operator=(const Poen& obj)
	{
		if (this == &obj)
			return *this;

		izgled = obj.Izgled;
		boja = obj.Boja;
		return *this;
	}

	~Poen() {};
};

ostream& operator<<(ostream& COUT, const Poen& obj)
{
	switch (obj.Boja)
	{
	case Boje::RED:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		break;
	case Boje::BLUE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

		break;
	case Boje::YELLOW:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

		break;
	case Boje::GREEN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

		break;
	case Boje::CYAN:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

		break;
	case Boje::PURPLE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

		break;
	}

	COUT << obj.Izgled;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return COUT;
}
bool operator ==(Poen& p1, Poen& p2)
{
	if ((p1.Izgled != p2.Izgled) && p1.Boja != p2.Boja)
		return false;
	return true;
}
bool operator !=(Poen& p1, Poen& p2)
{
	return !(p1 == p2);
}


class Igrac {
protected:
	bool vrstaIgraca; //0=kompjuter, 1=covjek
	int trenutnoKolona[3] = {0,0,0}; //0=index kolone
	Karta ruka[5];
	Poen** poeni;
public:
	Igrac()
	{
		poeni = new Poen * [3];
		for (int i = 0; i < 3; i++)
		{
			poeni[i] = nullptr;
		}
	}

	Igrac(bool covjekilikomp)
	{
		vrstaIgraca = covjekilikomp;

		poeni = new Poen*[3];
		for (int i = 0; i < 3; i++)
		{
			poeni[i] = new Poen[1];
		}
	}

	void prosiriNiz(Elementi element) 
	{

		trenutnoKolona[static_cast<int>(element)]++;

		//switch (element)				zakomentirani dio predstavlja kako bi izgledala prethodna linija koda da nisam saznao za static_cast
		//{
		//case Elementi::VATRA:
		//	trenutnoKolona[0]++;
		//	break;
		//case Elementi::VODA:
		//	trenutnoKolona[1]++;
		//	break;
		//case Elementi::SNIJEG:
		//	trenutnoKolona[2]++;
		//	break;
		//}

		Poen** temp=new Poen*[3];
		for (int i = 0; i < 3; i++)
		{

			temp[i] = new Poen[trenutnoKolona[i]+1];
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < trenutnoKolona[i]+1; j++)
			{
				temp[i][j] = poeni[i][j];
			}
		}
		poeni = temp;
		temp = nullptr;
	}

	void setPoen(Karta pobjednickaKarta)
	{
		Poen temp(pobjednickaKarta.Element, pobjednickaKarta.Boja);

		poeni[static_cast<int>(pobjednickaKarta.Element)][trenutnoKolona[static_cast<int>(pobjednickaKarta.Element)]]=temp;

		//switch (pobjednickaKarta.Element)		zakomentirani dio predstavlja kako bi izgledala prethodna linija koda da nisam saznao za static_cast
		//{
		//case Elementi::VATRA:
		//	poeni[0][trenutnoKolona[0]]=temp;
		//	break;
		//case Elementi::VODA:
		//	poeni[1][trenutnoKolona[1]]=temp;
		//	break;
		//case Elementi::SNIJEG:
		//	poeni[2][trenutnoKolona[2]]=temp;
		//	break;
		//}

		prosiriNiz(pobjednickaKarta.Element);
	}


	//namjeravao sam implementirati 2 klase "covjek" i "kompjuter" koje su izvedene iz klase igrac
	//ali sam shvatio da je jedina razlika tih klasa indeksiranje odabrane karte sto se vrlo lahko da rijesiti jednim bool atributom tj. "vrstaIgraca"

	void nacrtajOdabranuKartu(int odabir)
	{
		if(vrstaIgraca==1)
			cout << "Izabrali ste kartu:" << endl;
		if(vrstaIgraca==0)
			cout << "Protivnik je odabrao kartu:" << endl;
		cout << ruka[odabir - vrstaIgraca] << endl;
	}

	Karta getKarta(int index)const { return ruka[index - vrstaIgraca]; }

	void povuciKartu(int odabir)
	{												//u prosloj verziji igrice sam koristio liniju "new (&getruka()[odabir - 1]) Karta();"
		ruka[odabir - vrstaIgraca].~Karta();		//nisam bio u potpunosti siguran sta ova linija radi u pozadini jer sam je nasao na internetu,
		ruka[odabir - vrstaIgraca] = Karta();		//ali sada sam shvatio da je rijec o "placement new" operatoru koji ne alocira memoriju vec samo konstruiše na vec postojecoj memoriji
		//new (&ruka[odabir - vrstaIgraca])Karta();
	}

	//IGRAC JE POBJEDIO AKO IMA TRI POENA RAZLICITE BOJE I (ISTOG ILI RAZLICITOG ZNAKA)
	//buduci da se sada uzimaju u obzir i boje poena, funkcija za odredjivanje pobjednika je dosta kompleksnija
	bool pobjeda()
	{
		int poeniRazlicitihElemenata = 0;
		int poeniIstihElemenata = 1;

		Boje boja1, boja2;
		Boje bojaF, bojaW;

		if (trenutnoKolona[0] > 0 && trenutnoKolona[1] > 0 && trenutnoKolona[2] > 0)
		{
			for (int k = 0; k<trenutnoKolona[0]; k++)
			{
				poeniRazlicitihElemenata = 0;

				if (poeniRazlicitihElemenata == 0)
				{
					bojaF = poeni[0][k].Boja;
					poeniRazlicitihElemenata++;
				}

				if (poeniRazlicitihElemenata == 1)
				{
					for (int j = 0; j < trenutnoKolona[1]; j++)
					{
						if (poeni[1][j].Boja != bojaF)
						{
							bojaW = poeni[1][j].Boja;
							poeniRazlicitihElemenata++;
							break;
						}
					}
				}

				if (poeniRazlicitihElemenata == 2)
				{
					for (int l = 0; l < trenutnoKolona[2]; l++)
					{
						if (poeni[2][l].Boja != bojaF && poeni[2][l].Boja != bojaW)
							return true;
					}
				}
			}
		}



		for (int i = 0; i < 3; i++)
		{
			if (trenutnoKolona[i] >= 3)
			{
				boja1 = poeni[i][0].Boja;

				for (int j = 0; j < trenutnoKolona[i]; j++)
				{
					if ((poeni[i][j].Boja != boja1) && (poeniIstihElemenata==1))
					{
						boja2 = poeni[i][j].Boja;
						poeniIstihElemenata++;
					}

					if ((poeni[i][j].Boja != boja1) && (poeni[i][j].Boja != boja2) && (poeniIstihElemenata == 2))
						return true;

				}
				poeniIstihElemenata = 1;
			}
		}

		return false;
	}

	Poen getPoen(int red, int kol)const { return poeni[red][kol]; }
	int getTrenutnoKolona(int index)const { return trenutnoKolona[index]; }

	//_declspec(property(get = getPoen)) Poen Poen_;	izbacuje neki error koji mi nije jasan

	~Igrac() 
	{
		for (int i = 0; i < 3; i++)
		{
			delete[] poeni[i];
			poeni[i] = nullptr;
		}
		delete[] poeni;
		poeni = nullptr;
	};
};

ostream& operator<<(ostream& COUT, const Igrac& obj)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < obj.getTrenutnoKolona(i); j++)
		{
			COUT << obj.getPoen(i,j);
		}
		COUT << endl;
	}
	return COUT;
}

int main()
{
	srand(time(0));

	Igrac covjek(true), kompjuter(false);
	int odabir, ProtivnikovOdabir; 

	do
	{
		system("CLS");
		nacrtajIgraca();

		cout << "Karte u vasoj ruci su:" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << covjek.getKarta(i+1);
		}

		cout << "Odaberite koju kartu zelite odigrati (1-5)" << endl;
		do
		{
			cin >> odabir;			 //exception thrown card-jitsu 2.0.exe has triggered a breakpoint.!?!?!??!?!
		} while (odabir<1 || odabir>5);

		ProtivnikovOdabir = rand() % 5;

		covjek.nacrtajOdabranuKartu(odabir);
		kompjuter.nacrtajOdabranuKartu(ProtivnikovOdabir);

		if(covjek.getKarta(odabir)==kompjuter.getKarta(ProtivnikovOdabir))
			cout << "Nerjeseno"<<endl;

		else if (covjek.getKarta(odabir) > kompjuter.getKarta(ProtivnikovOdabir))
		{
			cout << "Tvoja karta je pobijedila"<<endl;
			covjek.setPoen(covjek.getKarta(odabir));
		}

		else if (kompjuter.getKarta(ProtivnikovOdabir) > covjek.getKarta(odabir))
		{
			cout << "Protivnikova karta je pobijedila"<<endl;
			kompjuter.setPoen(kompjuter.getKarta(ProtivnikovOdabir));
		}

		covjek.povuciKartu(odabir);
		kompjuter.povuciKartu(ProtivnikovOdabir);

		cout << "Tvoji poeni su: " << endl << covjek << "protivnikovi poeni su:" << endl <<kompjuter<<endl;
			
		system("pause");

	} while (!covjek.pobjeda() && !kompjuter.pobjeda());

	if (covjek.pobjeda())
		cout << "POBIJEDILI STE!" << endl;
	else 
		cout << "IZGUBILI STE!" << endl;

	cin.get();
	return 0;
}

//DESTRUKTORI, DEALOKACIJA