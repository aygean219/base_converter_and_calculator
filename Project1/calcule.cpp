//------------------//
//---NURLA AYGEAN---//
//------------------//
#include "numar.h"
#include "calcule.h"
#include <cstddef>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <iterator> 
#include <map>
#include "util.h"
using namespace std;

//constructor fara parametrii
//numarul initial ia valorea 0 si se afla in baza 10
Calcul::Calcul():Numar()
{
	this->transport = 0;
}
//constructor cu parametrii
Calcul::Calcul(string numar,int baza,int transport):Numar(numar,baza)
{
	
	this->transport = transport;
}
Calcul::Calcul(const Calcul& n):Numar(n)
{
	this->transport = n.transport;
}
//destructor
Calcul::~Calcul()
{
	//nu necesita curatarea memoriei manual,nu folosesc pointeri
}
//getteri
int Calcul::getTransport()
{
	return this->transport;
}
//setteri
void Calcul::setTransport(int t)
{
	this->transport = t;
}
//Suprascrierea operatorului = si ==
bool Calcul::operator==(const Calcul& n)
{
	
	return (this->Numar::operator==(n)) && (this->transport == n.transport);
}
Calcul& Calcul::operator=(const Calcul& n)
{
	this->Numar::operator==(n);
	this->setTransport(n.transport);
	return *this;

}
