#include "Bilet.h"


int main()
{
    int v[] = { 1,2,3,4 };
    int v1[] = { 1,1,1,1 };
    int v2[] = { 2,2,2,2 };
    int v3[] = { 4,5,6,7 };
    Locatie x1,z1;
    Eveniment x3;
    x3.setLocatie(x1);
    Eveniment x2((char*)"tip", "ora1", "data1", x1);
    Eveniment x4((char*)"tip", "ora2", "data1", x1);
    if (x2 == x4)
        cout << "da";
    else
        cout << "NU";
    Bilet y(x2, 4, v, v1);
    Bilet y3(x2, 4, v2, v3);
    Locatie::afisMatrice1();
    y.setnrLoc(v3, 4);
    y.setnrRand(v2, 4);
    //x2.cancelEveniment();
    x1.stergereLocatie();
    Locatie::afisMatrice1();
    y.afisVectid();
    y+= y3;
    
    Locatie::afisMatrice1();
    Bilet::afisVectid();
    Bilet::refund(y);
    Locatie::afisMatrice1();
    Bilet::afisVectid();
    return 0;
}