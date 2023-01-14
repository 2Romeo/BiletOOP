#include "Bilet.h"

//ofstream g("Bilet.bin", ios::out | ios::binary | ios::ate);
int main()
{
	ofstream g;
	g.open("fisier.txt", ios::out | ios::binary);
	vector <Bilet> bilete;
	int i, j, aux, mmm;
	//~~~~~~~~~~~MENIU~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "Puteti alege din urmatoarele: " << endl;
	cout << "1-Cumpara bilet" << endl;
	cout << "2-Returneaza bilet" << endl;
	cout << "3-Valideaza bilet" << endl;
	cout << "Introduceti alegerea: ";
	cin >> mmm;
	while (mmm)
	{
		switch (mmm)
		{
		case 1:
		{	int zzz = 1;
		while (zzz) {


			cout << "introduceti datele biletului: " << endl;
			Bilet x;
			cin >> x;
			//x.afisVectid();
			//Locatie::afisMatrice1();

			cout << "Sunteti 1-elev sau student/2-persoana cu dizabilitati/3-ambele/4-nicio alegere " << endl;
			cin >> aux;
			if (aux == 1)
			{
				Student_sau_elev xx3;
				xx3.setBilet(x);
				xx3.setPret();
				bilete.push_back(xx3.getBilet());
				xx3.setPret();
				//xx3.afiseazadate();
				//Bilet::afisVectid();
			}
			else
				if (aux == 2)
				{
					Persoana_cu_dizabilitati xx4;
					xx4.setBilet(x);
					xx4.setPret();
					bilete.push_back(xx4.getBilet());
					xx4.setPret();
					//xx4.afiseazadate();
					//Bilet::afisVectid();
				}
				else
					if (aux == 3)
					{

						Persoana_cu_dizabilitati xx5;//sau Student_sau_elev xx4
						xx5.setBilet(x);
						xx5.setPret();
						bilete.push_back(xx5.getBilet());
						xx5.setPret1(0);
						//	xx5.afiseazadate();
					//	Bilet::afisVectid();

					}
					else
						if (aux == 4)
						{
							bilete.push_back(x);//punem biletul normal in vector 
						}
						else
						{
							bilete.push_back(x);
							cout << "input gresit " << endl;
						}
			if (aux == 1 || aux == 2 || aux == 3)
			{
				for (i = 0; i < Locatie::getNrLocOcupate(); i++)// pentru stergerea id-ului biletlului x format la inceput
					if (x.getid() == Bilet::getvectid(i))
					{
						for (j = i; j < Locatie::getNrLocOcupate() - 1; j++)
							Bilet::setVectid(j, Bilet::getvectid(j + 1));
						Bilet::setVectid(j, 0);
					}
				//cout << "vectid: "; Bilet::afisVectid();
				Locatie::setnrLocOcupate(-1);
				aux = 0;
			}
			//delete y11;
			cout << "Cumparati alt bilet ?[DA/NU]" << endl;
			string rasp;
			cin >> rasp;
			if (rasp != "DA" && rasp != "dA" && rasp != "da" && rasp != "Da")

				zzz = 0;
		}
		break;

		}

		case 2: {	int id, i, ok, ok1 = 1;
			//Bilet::afisVectid();
			cout << "introduceti id-ul biletului dumneavoastra";
			cin >> id;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
				cin >> id;
			}
			while (ok1) {
				ok = 0;
				for (i = 0; i < Locatie::getNrLocOcupate(); i++)
					if (id == Bilet::getvectid(i))
						ok = 1;
				if (ok == 1)
				{
					for (int i = 0; i < bilete.size(); i++)
						if (bilete[i].getid() == id)
						{
							cout << "Bilet rambursat" << endl;
							Bilet::refund(bilete[i]);
							//		bilete.erase(bilete.begin() + i);
							break;
						}
				}
				else
					cout << "id-ul este invalid" << endl;
				//Bilet::afisVectid();
				string rasp;
				cout << "introduceti alt id?[Y/N] " << endl;
				cin >> rasp;
				if (rasp == "y" || rasp == "Y")
				{
					cout << "introduceti id-ul: " << endl;
					cin >> id;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
						cin >> id;
					}
				}
				else
				{
					ok1 = 0;
					break;
				}

			}
			break;
		}
		case 3:
		{	int id, i, ok, ok1 = 1;
		cout << "introduceti id-ul biletului dumneavoastra";
		cin >> id;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
			cin >> id;
		}
		while (ok1) {
			ok = 0;
			for (i = 0; i < Locatie::getNrLocOcupate(); i++)
				if (id == Bilet::getvectid(i))
					ok = 1;
			if (ok == 1)
				cout << "bilet valid" << endl;
			else
				cout << "bilet invalid" << endl;
			string rasp;
			cout << "introduceti alt id?[Y/N] " << endl;
			cin >> rasp;
			if (rasp == "y" || rasp == "Y")
			{
				cout << "introduceti id-ul: " << endl;
				cin >> id;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
					cin >> id;
				}
			}
			else
			{
				ok1 = 0;
				break;
			}

		}
		break;
		}
		default: {cout << "Nu ati introdus corect" << endl; break; }
		}

		cout << "alegeti altcv ?[DA/NU]" << endl;
		string rasp;
		cin >> rasp;
		if (rasp == "DA" || rasp == "dA" || rasp == "da" || rasp == "Da")
		{
			cout << "Puteti alege din urmatoarele: " << endl;
			cout << "1-Cumpara bilet" << endl;
			cout << "2-Returneaza bilet" << endl;
			cout << "3-Valideaza bilet" << endl;
			cout << "Introduceti alegerea: ";
			int mm;
			cin >> mm;
			mmm = mm;
		}
		else
			mmm = 0;


	}
	for (i = 0; i < bilete.size(); i++)
	{
		g << "----------Bilet " << endl;
		g << bilete[i] << endl;
	}
}
