//------------------//
//---NURLA AYGEAN---//
//------------------//
/*
Clasa Numar are ca atribute un numar de tipul string si un intreg baza,
reprezentand baza in care se afla numarul respectiv.
*/
#pragma once
#include <ostream>
#include <string>
using namespace std;
class Numar {
protected:
	string numar;//numarul
	int baza;//baza in care se afla numarul
public:
	//constructori pentru clasa Numar
	Numar();
	Numar(string, int);
	Numar(const Numar&);
	//destructor pentru clasa Numar
	~Numar();
	//getteri
	string getNumar();
	int getBaza();
	//setteri
	void setNumar(string);
	void setBaza(int);
	//suprascrierea operatorului egal
	Numar& operator=(const Numar& n);
	bool operator==(const Numar& n);
	//afiseaza Numarul impreuna cu baza sa delimitandu-le cu "delimitator"
	string toString(string delimitator);
	//Redefinirea operatiilor 
	Numar suma( Numar b); //Suma dintre 2 Numere
	Numar diferenta(Numar b);//Diferenta dintre 2 Numere
	Numar inmultire(char b);//Inmultirea cu o cifra a unui Numar
	Numar impartire( char b);//Impartirea cu o cifra a unui Numar
	Numar inmultire_cu_2_cifre(string b);//Inmultirea unui Numar cu un al Numar care are 2 cifre
	Numar comparare(Numar);//Compararea a 2 a Numere
};