#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

public:

	//constructori - in acest caz fara parametri, implicit daca il stergem
	Student()
	{
		this->note = nullptr;
		this->adresa = nullptr;
		this->nume = "";
		this->varsta = -1;
		//etc
	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->set_note(_note, _numar_materii);

		//this->note = new int[_numar_materii];
		//for (int index = 0; index < _numar_materii; index++)
		//{
		//	this->note[index] = _note[index];
		//}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer


	/*Student(const Student& student) :
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}*/


	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii


	Student(const Student& student)
	{
		this->note = student.note;
		if (this->adresa != NULL)
			delete[] this->adresa;
		this->adresa = new char[strlen(student.adresa) + 1];
		strcpy(this->adresa ,student.adresa);
		this->nume = student.nume;
		this->varsta = student.varsta;
	}


	//setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note; ar copia doar adresa notei, fara valoarea notei

		if (this->note != nullptr)
			delete[] this->note; // [] necesar pentru a sterge tot array-ul din memorie pentru a elibera memoria inainte de re-alocare cu alte valori.
		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_nume(string _nume) {
		this->nume = _nume;
	}
	void set_adresa(char* _adresa) {
		this->adresa = new char[20];
		strcpy_s(this->adresa, 20, "Bucuresti, Sector 1");
	}
	void set_varsta(int _varsta) {
		this->varsta = _varsta;
	}
	void set_an_studii(int _an_studii) {
		this->an_studii = _an_studii;
	}
	void set_numar_matricol(string _nr_matricol)
	{

		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete[] this->adresa;
		delete[] this->note;
	}
private: //toti cei 4 membri nu pot fi interogati prin main
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

class Book
{
	char* author;
	char* title; // string also accepted
	int pages_nr;
	int* page_wordcount;
	bool online;

public:
	char* getauthor() { return this->author; }
	char* gettitle() { return this->title; }
	int getpages_nr() { return this->pages_nr; }
	int* getpage_wordcount() { return this->page_wordcount; }
	bool getonline() { return this->online; }

	void setauthor(char* author)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
	}
	void settitle(char* title)
	{
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
	}
	void setpages_nr(int pages_nr) { this->pages_nr = pages_nr; }
	void setpage_wordcount(int* page_wordcount)
	{
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[this->pages_nr];
		for (int i = 0; i < this->pages_nr; i++)
			this->page_wordcount[i] = page_wordcount[i];
	}
	void setonline(bool online) { this->online = online; }

	Book(char* author, char* title, int pages_nr, int* page_wordcount, bool online)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[pages_nr];
		for (int i = 0; i < pages_nr; i++)
			this->page_wordcount[i] = page_wordcount[i];
		this->pages_nr = pages_nr;
		this->online = online;
	}
	Book (const Book& b)
	{
		if (this->author != NULL)
			delete[] this->author;
		this->author = new char[strlen(b.author) + 1];
		strcpy(this->author, b.author);
		if (this->title != NULL)
			delete[] this->title;
		this->title = new char[strlen(b.title) + 1];
		strcpy(this->title, b.title);
		this->pages_nr = b.pages_nr;
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
		this->page_wordcount = new int[pages_nr];
		for (int i = 0; i < b.pages_nr; i++)
			this->page_wordcount[i] = b.page_wordcount[i];
		this->online = b.online;
	}
	~Book()
	{
		if (this->author != NULL)
			delete[] this->author;
		if (this->title != NULL)
			delete[] this->title;
		if (this->page_wordcount != NULL)
			delete[] this->page_wordcount;
	}
};

int main()
{
	Student s0; //interogheaza primul constructor, cel fara parametri
	////s0.get_numar_matricol = "Ugkdflk";

	//s0.nume = "Anghel Mihai";
	//s0.adresa = new char[20]; //alocare memorie (dinamica)
	//strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");

	//s0.varsta = 21;
	//s0.an_studii = 2;

	////de ce este generata eroarea?
	////s0.note = new int[20];

	s0.set_nume("Alex");
	s0.set_adresa((char*)"STR CNSL 4");
	s0.set_varsta(21);
	s0.set_an_studii(2024);
	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);


	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	//Student s2 = s1; throw exception;
	//s2.nume = "Ionescu C";

	int page_wordcount[10] = { 100, 23, 48, 28, 57, 55, 147, 52, 62, 52 };
	char author[] = "Cazacu Brindusa";
	char title[] = "o zi minunata";
	Book b(author, title, 10, page_wordcount, true);
	Book b1 = b;
}



//in clasa daca nu specificam atributele, devin private
//daca schimbam un membru in cadrul structurii, implicit putem face asta
//private > nu mai putem schimba membrii structurii

// constructor = metoda care construieste un obiect
// tipuri: implicit > daca e specificat de noi este ori cu parametri ori fara parametri
// tot ce am discutat la clase merge si la constructori in afara de vizibilitate