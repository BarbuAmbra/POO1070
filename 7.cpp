#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
#include<cassert>
using namespace std;

class Fractie
{
private:
    int m_numarator{ 0 };
    int m_numitor{ 1 };
    static int x;
    static int count;

public:
   // void setx(static int x) { Fractie::x = x; }
   // static int getx() { return x; }


    // Default constructor
    Fractie(int numarator = 0, int numitor = 1)
        : m_numarator(numarator), m_numitor(numitor)
    {
        this->m_numitor = numitor;
        this->m_numarator = numarator;
        //m_numitor = numitor;
        //m_numarator = numarator;

        //assert(numitor != 0);
        Fractie::count++;
    }

    // Copy constructor
    Fractie(const Fractie& copy)
        : m_numarator{ copy.m_numarator }, m_numitor{ copy.m_numitor }
    {
        // nu mai este nevoie de verificarea numitorului pentru ca operatiile se fac asupra a doua obiecte existente - au fost verificate in cadrul constructorului
        cout << "S-a apelat constructorul de copiere.\n";
    }

    // Supraincarcarea operatorului de atribuire:  =
   // Fractie& operator= (const Fractie& fractie);
    void operator= (const Fractie& fractie);

    //Fractie& operator= (const Fractie& fractie) = delete; // nu se permite efectuarea copiilor prin asignare!
};

int Fractie::x = 0;
// O alta implementare => void??

void Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie)
        return;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return;
}


// O implementare mai buna - corecta => discutie
/*
Fractie& Fractie::operator= (const Fractie& fractie)
{
    // se evita autoasignarea
    if (this == &fractie)
        return *this;

    m_numarator = fractie.m_numarator;
    m_numitor = fractie.m_numitor;


    return *this;
}
*/

static void setcount(int count) {
    Fractie::count = count;
}
void SetCount(int count) {
    Fractie::count = count;
}

int main()
{ 
    //Fractie::setx(2);
   // Fractie::x = 3;
    //cout << Fractie::getx();
    Fractie fff(1, 2);
    Fractie fff1;
    fff1 = fff;
    Fractie fff2 =fff;
    //ff2.SetCount(9);
    //Fractie::setcount(10);
    Fractie _5p3{ 5, 3 };
    Fractie f = _5p3;
    Fractie ff;      //cine se apeleaza?
    ff = _5p3; //cine se apeleaza?

    Fractie f1{ 5, 3 };
    Fractie f2{ 7, 2 };
    Fractie f3{ 9, 5 };

    f1 = f2 = f3; //asignare inlantuita
   // f1 = f2;// = f3; //asignare inlantuita

   // f1 = f1; // autoasignare


   // return 0;
}
/*Implementati o clasa care sa lucreze cu siruri de caractere, asemeni clasei String din std
class My String{
char* str;
int len;
public:
constructor cu 2 parametrii
constructor copiere
metode de set si get
destructor
supraincarcare operator=};
exemplificare in main pentru toate functionalitatile
evidentiere apel constructor cu parametrii
evidentiere apel constructor de copiere
evidentiere operator egal*/
