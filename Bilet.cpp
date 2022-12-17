
#include "Bilet.h"

int Locatie::matriceLocuri[5000][5000] = { 0 };
int Locatie::nrMaximLocuri = 50;
int Locatie::nrMaximRanduri = 50;
int Locatie::nrLocOcupate = 0;
int Bilet::vectid[5000] = { NULL };
string Locatie::status = "necunoscut";

Locatie& Locatie::operator++() {
    nrMaximRanduri++;
    nrMaximLocuri++;
    return *this;
};
Locatie& Locatie::operator++(int) {
    Locatie copie = *this;
    copie.nrMaximLocuri++;
    copie.nrMaximRanduri++;
    return copie;
};
Locatie& Locatie::operator--() {
    nrMaximRanduri--;
    nrMaximLocuri--;
    return *this;
};
Locatie& Locatie::operator--(int) {
    Locatie copie = *this;
    copie.nrMaximLocuri--;
    copie.nrMaximRanduri--;
    return copie;
};
void Locatie::setnrLocOcupate(int x)
{   if(x>0)
    nrLocOcupate += x;
}
void Locatie::setNrMaximLocuri(int x)
{   if(x>0)
    nrMaximLocuri = x;
}
void Locatie::setNrMaximRanduri(int x)
{if(x>0)
    nrMaximRanduri = x;
}
void Locatie::setMatrice(int matrice[5000][5000], int n, int m)
{
    if (n > 0 && m > 0) {
        int i, j;
        Locatie::setNrMaximLocuri(m);
        Locatie::setNrMaximRanduri(n);
        for (i = 0; i < nrMaximRanduri; i++)
            for (j = 0; j < nrMaximLocuri; j++)
                matriceLocuri[i][j] = matrice[i][j];

    }
}
string Locatie::getstatus()
{
    return status;
}
Locatie::Locatie() {
    status = "Necunoscut";
}
Locatie& Locatie::operator=(const Locatie& x)
{
    if (this != &x) {

        Locatie::setMatrice(x.matriceLocuri, x.nrMaximRanduri, x.nrMaximLocuri);
    }
    return *this;
}
void Locatie::stergereLocatie() {
    status = "Libera";
    for (int i{ 0 }; i < nrMaximRanduri; i++)
        for (int j{ 0 }; j < nrMaximLocuri; j++)
            matriceLocuri[i][j] = 0;
}
void Locatie::setStatus(string x)
{
    if (x.empty())
    cout << "string is empty";
    else
    status = x;
}
istream& operator>>(istream& in, Locatie& x)
{
    int nrmaximRand, nrmaximLoc, nrlocOcupate;
    string status;
    cout << "Locatia este inchiriata(ocupata)?[DA/NU] ";
    in >> status;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> status;
    }
    if (status == "da" || status == "Da" || status == "dA" || status == "DA")
    {
        x.setStatus("inchiriat");
        cout << "Numarul maxim de randuri: ";
        in >> nrmaximRand;
        x.setNrMaximRanduri(nrmaximRand);
        cout << "Numarul maxim de locuri/rand: ";
        in >> nrmaximLoc;
        x.setNrMaximLocuri(nrmaximLoc);
     
    }
    else
        x.setStatus("liber");
    return in;
}
ostream& operator<<(ostream& out, Locatie& x)
{
    out << "nr de locuri ocupate " << x.nrLocOcupate << endl;
    out << "nr Maxim de randuri " << x.nrMaximRanduri << endl;
    out << "nr Maxim de locuri pe rand" << x.nrMaximLocuri << endl;
    out << "status " << x.status<<endl;
    return out;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Locatie::afisMatrice1()
{
    int i, j, maxRand = 0, maxLoc = 0;
    for (i = 0; i < nrMaximRanduri; i++)
        for (j = 0; j < nrMaximLocuri; j++)
            if (matriceLocuri[i][j] == 1)
            {
                if (i > maxRand)
                    maxRand = i;
                if (j > maxLoc)
                    maxLoc = j;
            }
    if (maxRand > 0 && maxLoc > 0) {
        for (i = 0; i <= maxRand; i++)
        {
            for (j = 0; j <= maxLoc; j++)
                cout << matriceLocuri[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    else
    {
        cout << "niciun loc ocupat" << endl;
    }
}
string Eveniment::getOra()
{
    return ora;
}
string Eveniment::getData()
{
    return data;
}
Locatie Eveniment::getLoc()
{
    return loc;
}
char* Eveniment::getTip()
{
    return tip;
}
void Eveniment::setora(string x)
{
    if (x.empty())
        cout << "string is empty";
    else
    ora = x;
}
void Eveniment::setTip(char* x)
{
    if (x != nullptr)
    {
        if (tip != nullptr)
            delete[] tip;
        tip = new char[strlen(x) + 1];
    }
}
void Eveniment::setdata(string x)
{
    if (x.empty())
        cout << "string is empty";
    else
    data = x;
}
void Eveniment::setLocatie(Locatie& x)
{
    loc = x;
}
void Eveniment::cancelEveniment() {
    delete[] tip;
    tip = new char[8];
    strcpy(tip, "necunoscut");
    ora = "Neprogramata";
    data = "Neprogramata";
    Locatie::stergereLocatie();
}
bool Eveniment::InsuficienteLocuri(int x) {
    bool ok = 1;
    if (loc.nrMaximLocuri * loc.nrMaximRanduri - loc.nrLocOcupate < x)
        ok = 0;
    return ok;
}
Eveniment::Eveniment(char* tip1, string ora1, string data1, Locatie& x)
{
    if (tip1 != nullptr)
        tip = new char[strlen(tip1) + 1];
    strcpy(tip, tip1);
    ora = ora1;
    data = data1;
    loc = x;
}
bool Eveniment::operator==(const Eveniment& x)
{
    bool ok = 1;
    if (ora != x.ora)
        ok = 0;
    if (data != x.data)
        ok = 0;
    if (loc != x.loc)
        ok = 0;
    if (strcmp(tip, x.tip) != 0)
        ok = 0;
    return ok;
}
bool Eveniment::operator>(const Eveniment& x)
{
    bool ok = 1;
    if (loc.nrMaximLocuri < x.loc.nrMaximLocuri)
        ok = 0;
    if (loc.nrMaximRanduri < x.loc.nrMaximRanduri)
        ok = 0;
    if (loc.nrLocOcupate < x.loc.nrLocOcupate)
        ok = 0;
    return ok;
}
Eveniment::~Eveniment()
{
  
        delete[] tip;
}
Eveniment::Eveniment()
{
    tip = nullptr;
}
Eveniment& Eveniment::operator=(const Eveniment& x)
{
    if (this != &x)
    {
        loc = x.loc;
        if (x.tip != nullptr)
        {
            if (tip != nullptr)
                delete[] tip;
            tip = new char[strlen(x.tip) + 1];
            strcpy(tip, x.tip);
        }
        ora = x.ora;
        data = x.data;
    }
    return *this;
}
istream& operator>>(istream& in, Eveniment& x)
{
    string ora, data;
    Locatie loc;
    char tip[50];
    cout << "Tipul de eveniment: ";
    in >> tip;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> tip;
    }
    if (x.tip != nullptr)
        delete[] x.tip;
    x.tip = new char[strlen(tip) + 1];
    strcpy(x.tip, tip);
    cout << "ora ";
    in >> ora;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> ora;
    }
    x.ora = ora;
    cout << "data ";
    in >> data;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> data;
    }
    x.data = data;
    cout << "Locatia evenimentului ";
    in >> loc;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> loc;
    }
    x.loc = loc;
    return in;
}
ostream& operator<<(ostream& out, Eveniment& x)
{
   /* char tip1[50];
    strcpy(tip1, x.tip);
   */
    out << "Denumirea evenimentului " << x.tip << endl;
    out << "Ora evenimentului " << x.ora << endl;
    out << "Data evenimentulu " << x.data << endl;
    out << "Locatie " << x.loc << endl;
    return out;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Bilet::setnrRand(int* x, int nr)
{
    if (nr <= nrBilete)
    {
        int i;
        if (nrRand != nullptr && nrLoc != nullptr) {
            for (i = 0; i < nrBilete; i++)
                evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 0;
            delete[] nrRand;
        }
        nrBilete = nr;
        nrRand = new int[nr];
        for (i = 0; i < nr; i++)
            nrRand[i] = x[i];
        if (nrRand != nullptr && nrLoc != nullptr)
            for (i = 0; i < nrBilete; i++)
                evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 1;
    }
}
void Bilet::setnrLoc(int* x, int nr)
{
    if (nrBilete <= nr)
    {
        int i;
        if (nrLoc != nullptr) {
            for (i = 0; i < nrBilete; i++)
                evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 0;
            delete[] nrLoc;
        }
        nrLoc = new int[nr];
        for (i = 0; i < nr; i++)
            nrLoc[i] = x[i];
        nrBilete = nr;
        if (nrRand != nullptr && nrLoc != nullptr)
            for (i = 0; i < nrBilete; i++)
                evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 1;
    }
}
void Bilet::setNrBilete(int x)
{
    if (x > 0)
        nrBilete = 0;
}
void Bilet::setEvenim(Eveniment& x)
{
    evenim = x;
}
int* Bilet::getnrLoc()
{
    return nrLoc;
}
int* Bilet::getnrRand()
{
    return nrRand;
}
int Bilet::getid()
{
    return id;
}
int Bilet::getnrBilete()
{
    return nrBilete;
}
Bilet& Bilet::operator=(const Bilet& x)
{
    if (this != &x)
    {
        int i;
        evenim = x.evenim;
        if (x.nrBilete >= 0)
            nrBilete = x.nrBilete;
        if (x.nrLoc != nullptr && x.nrRand != nullptr)
        {
            if (nrLoc != nullptr)
                delete[] nrLoc;
            if (nrRand != nullptr)
                delete[] nrRand;
            nrLoc = new int[nrBilete];
            nrRand = new int[nrBilete];
            for (int i{ 0 }; i < nrBilete; i++)
            {
                nrLoc[i] = x.nrLoc[i];
                nrRand[i] = x.nrRand[i];
            }
            for (i = 0; i < x.evenim.loc.nrMaximLocuri; i++)
                vectid[i] = x.vectid[i];
        }
    }
    return *this;
}
void Bilet::setVectid(int i, int k)
{  
    vectid[i] = k;
}
int Bilet::generateid()
{
    int len = Bilet::evenim.loc.nrLocOcupate;
    int ok = 1;
    int id1 = rand();
    while (ok != 0)
    {
        ok = 0;
        for (int i = 0; i < len; i++)
            if (id1 == vectid[i]||id1==0)
            {
                id1 = rand();
                ok = 1;
            }
    }
    Bilet::setVectid(len, id1);
    Locatie::setnrLocOcupate(1);
    return id1;
}
Bilet::Bilet() :id(generateid())
{
    nrLoc = nullptr;
    nrRand = nullptr;


}
Bilet::Bilet(Eveniment& x, int nrbil, int* nrloc, int* nrrand) :Bilet()//, id(generateid())
{
    int i, ok = 0; int k = 0; int aux[100] = { NULL };
    for (i = 0; i < nrbil; i++)
        if (Bilet::evenim.loc.matriceLocuri[nrrand[i] - 1][nrloc[i] - 1] == 1)
        {
            aux[k] = i; k++; ok = 1;
        }
    if (ok)
    {
        cout << "locul/rile ";
        for (i = 0; i < k; i++)
            cout << nrloc[aux[i]] << " ";
        cout << "ocupat/e; " << endl;
    }
    else
    {
        evenim = x;
        nrBilete = nrbil;
        nrLoc = new int[nrBilete];
        nrRand = new int[nrBilete];
        for (i = 0; i < nrBilete; i++)
        {
            nrLoc[i] = nrloc[i];
            nrRand[i] = nrrand[i];
        }
        for (i = 0; i < nrBilete; i++)
            Bilet::evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 1;
    }
}
Bilet::~Bilet()
{
    delete[] nrLoc;
    delete[] nrRand;
}
void Bilet::afisVectid()
{
    for (int i{ 0 }; i < Locatie::nrLocOcupate; i++)
        cout << vectid[i] << " ";
    cout << endl;
}
int Bilet::operator[](int k)
//returneaza randul unui loc primit ca parametru
{

    int i;
    for (i = 0; i < nrBilete; i++)
        if (nrLoc[i] == k)
            return nrRand[i];

    return NULL;
}
bool Locatie:: operator!=(const  Locatie& x)
{
    bool ok = 0;
    if (nrLocOcupate != x.nrLocOcupate)
        ok = 1;
    if (nrMaximLocuri != x.nrMaximLocuri)
        ok = 1;
    if (nrMaximRanduri != x.nrMaximRanduri)
        ok = 1;
    // unspecified error |
   //                    v
    if (nrMaximLocuri == x.nrMaximLocuri && nrMaximRanduri == x.nrMaximRanduri)
        for (int i{ 0 }; i < nrMaximRanduri; i++)
            for (int j{ 0 }; j < nrMaximLocuri; j++)
                if (matriceLocuri[i][j] != x.matriceLocuri[i][j])
                    ok = 1;
    return ok;
}
Bilet& Bilet::operator+=(const Bilet& x) {
    int i;
    int* auxLoc = new int[nrBilete + x.nrBilete];
    int* auxRand = new int[nrBilete + x.nrBilete];
    for (i = 0; i < nrBilete; i++)
    {
        auxLoc[i] = nrLoc[i];
        auxRand[i] = nrRand[i];
    }
    for (i = nrBilete; i < nrBilete + x.nrBilete; i++)
    {
        auxLoc[i] = x.nrLoc[i-nrBilete];
        auxRand[i] = x.nrRand[i-nrBilete];
    }
    for (i = 0; i < evenim.loc.nrLocOcupate; i++)
        if (x.id == vectid[i])
            for (int j{ i }; j < evenim.loc.nrLocOcupate; j++)
                Bilet::setVectid(j, vectid[j + 1]);//stergem id-ul biletului pe care l-am adunat

    Locatie::setnrLocOcupate(-1);//ptr ca am sters id
    delete[] nrLoc, nrRand;
    nrBilete += x.nrBilete;
    nrRand = new int[nrBilete];
    nrLoc = new int[nrBilete];
    for (i = 0; i < nrBilete; i++)
    {
        nrLoc[i] = auxLoc[i];
        nrRand[i] = auxRand[i];
    }

    return *this;
}
void Bilet::refund(Bilet& x)
{
    int ok = 0, i;
    for (i = 0; i < x.evenim.loc.nrLocOcupate; i++)
        if (x.id == vectid[i])
        {
            ok = 1;
            for (int j{ i }; j < x.evenim.loc.nrLocOcupate; j++)
            {
                Bilet::setVectid(j, vectid[j + 1]);//stergem id-ul

                if (j == x.evenim.loc.nrLocOcupate - 1)
                {
                    Locatie::setnrLocOcupate(-1);
                    break;
                }
            }
        }
    if (ok == 1)
    {
        for (i = 0; i < x.nrBilete; i++)
            x.evenim.loc.matriceLocuri[x.nrRand[i] - 1][x.nrLoc[i] - 1] = 0;

    }
    else
        cout << "bilet invalid" << endl;
}
istream& operator>>(istream& in, Bilet& x)
{
    Eveniment evenim;
    int nrbil, i;
    float pret;
    int* nrLoc, * nrRand;
    cout << "nr de locuri pe care doriti sa le ocupati: ";
    in >> nrbil;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> nrbil;
    }
    nrLoc = new int[nrbil];
    nrRand = new int[nrbil];
    x.nrLoc = new int[nrbil];
    x.nrRand = new int[nrbil];
    x.nrBilete = nrbil;
    cout << "introduceti locurile pe care le doriti ";
    for (i = 0; i < nrbil; i++)
    {
        in >> nrLoc[i];
        while (in.fail())
        {
            in.clear();
            in.ignore(100, '\n');
            cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
            in >> nrLoc[i];
        }
        x.nrLoc[i] = nrLoc[i];
    }
    cout << "introduceti randul/rile pe care le doriti ";
    for (i = 0; i < nrbil; i++)
    {
        in >> nrRand[i];
        while (in.fail())
        {
            in.clear();
            in.ignore(100, '\n');
            cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
            in >> nrRand[i];
        }
        x.nrRand[i] = nrRand[i];
    }
    for (i = 0; i < nrbil; i++)
        // x.evenim.loc.matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 1;
        Locatie::matriceLocuri[nrRand[i] - 1][nrLoc[i] - 1] = 1;
    cout << "Evenimentul: ";
    in >> evenim;
    while (in.fail())
    {
        in.clear();
        in.ignore(100, '\n');
        cout << "   nu ati introdus corect " << endl << "   incercati din nou: ";
        in >> evenim;
    }
    x.evenim = evenim;
    return in;
}
ostream& operator<<(ostream& out, Bilet& x)
{
    int i;
    out << "nr de locuri ocupate" << x.nrBilete << endl;
    out << "Locurile ocupate ";
    for (i = 0; i < x.nrBilete; i++)
        out << x.nrLoc[i] << " ";
    out << endl;
    out << "Randurile ocupate ";
    for (i = 0; i < x.nrBilete; i++)
        out << x.nrRand[i] << " ";
    /*  out << "vectorul de id-uri ";
      for (int i{ 0 }; i < Locatie::nrLocOcupate; i++)
          out << x.vectid[i] << " ";*/
    out << endl;
    out << "id-ul biletului " << x.id << endl;
    out << "evenimentul " << endl;
   out << x.evenim;
    return out;
}
