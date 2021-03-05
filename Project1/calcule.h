//------------------//
//---NURLA AYGEAN---//
//------------------//
/*
Clasa Calcul mosteneste clasa Numar si are ca scop in cazul in care in cadrul
ultimei operatii efectuate rezultatul are un transport necesar in alte calcule
sa fie pastrat cu ajutorul variabilei transport
*/
#pragma once
#include <ostream>
#include <string>
#include "numar.h"
using namespace std;
class Calcul :public Numar{
private:
	int transport;
public:
	//constructori pentru clasa Calcul
	Calcul();
	Calcul(string,int, int);
	Calcul(const Calcul&);
	//destructor
	~Calcul();
	//setteri
	void setTransport(int);
	//getteri
	int getTransport();
	//suprascrierea operatorului egal
	Calcul& operator=(const Calcul& n);
	bool operator==(const Calcul& n);
	
	
};