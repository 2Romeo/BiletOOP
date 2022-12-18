#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#pragma warning(disable:4996)
class Bilet;
class Eveniment;
class Locatie {
private:
	friend class Eveniment;
	friend class Bilet;
	static int nrMaximLocuri;
	static int nrMaximRanduri;
	static int matriceLocuri[5000][5000];
	static int nrLocOcupate;
	static string status;
public:
	Locatie& operator--();
	Locatie& operator--(int);
	Locatie& operator++();
	Locatie& operator++(int);
	static void setnrLocOcupate(int);
	static void setStatus(string);
	static void setNrMaximLocuri(int);//pe rand
	static void setNrMaximRanduri(int);
	static void setMatrice(int a[5000][5000], int, int);
	static int getNrMaximLocuri();
	static int getNrMaximRanduri();
	static int getMatriceLocuri();
	void setVectid(int);
	static void afisMatrice1();//~
	bool operator!=(const Locatie&);
	Locatie& operator=(const Locatie&);
	string getstatus();
	Locatie();
	static void stergereLocatie();//~~
	friend istream& operator>>(istream&, Locatie&);
	friend ostream& operator<<(ostream&, Locatie&);

	//friend istream& operator>>(istream&, Eveniment&);
	//friend ostream& operator<<(ostream&, Eveniment);

	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet&);

	//Locatie(int[5000]);
	//~Locatie();
};

class Eveniment {
	friend class Locatie;
	friend class Bilet;
	char* tip;//denumirea evenimentului
	string ora;
	string data;
	Locatie loc;
public:
	bool operator>(const Eveniment&);
	bool operator==( const Eveniment&);
	void setTip(char*);
	void setora(string);
	void setdata(string);
	void setLocatie(Locatie&);
	char* getTip();
	string getOra();
	string getData();
	Locatie getLoc();
	void cancelEveniment();//--
	Eveniment();
	bool InsuficienteLocuri(int);
	Eveniment(const Eveniment&);
	Eveniment(char*, string, string, Locatie&);
	Eveniment& operator=(const Eveniment&);
	~Eveniment();
	friend istream& operator>>(istream&, Eveniment&);
	friend ostream& operator<<(ostream&, Eveniment&);

	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet&);
};

class Bilet {
	friend class Eveniment;
	friend class Locatie;
	Eveniment evenim;
	int nrBilete;//nr de locuri ocupate de pe bilet
	//float pret;
	int* nrLoc, * nrRand;
	static int vectid[5000];
	const int id;

public:
	int operator[](int);
	void setEvenim(Eveniment&);
	void setNrBilete(int);
	//void setPret(float);
	static void setVectid(int, int);
	void setnrLoc(int*,int);
	void setnrRand(int*,int);
	int getNrBilete();
	float getpret();
	static void afisVectid();//~~~
	static void refund(Bilet& y);//~~~
	Eveniment getevenim();
	Bilet();
	Bilet(Eveniment&, int, int*, int*);
	Bilet(const Bilet&);
	~Bilet();
	//	void afisMatrice();
	Bilet& operator=(const Bilet&);
	Bilet& operator+=(const Bilet&);
	int generateid();//~~~
	int* getnrLoc();
	int* getnrRand();
	int getid();
	int getnrBilete();
	friend istream& operator>>(istream&, Bilet&);
	friend ostream& operator<<(ostream&, Bilet&);
};
