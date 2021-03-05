//------------------//
//---NURLA AYGEAN---//
//------------------//
#include "numar.h"
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
Numar::Numar()
{
	this->numar = "";
	this->baza = 10;
}
//constructor cu parametrii
Numar::Numar(string numar, int baza)
{
	this->numar = numar;
	this->baza = baza;
}
//constructor
Numar::Numar(const Numar& n)
{
	this->numar = n.numar;
	this->baza = n.baza;
}
//destructor
Numar::~Numar()
{
	//nu necesita curatarea memoriei manual,nu folosesc pointeri
}
//getteri
//returneaza numarul
string Numar::getNumar()
{
	return this->numar;
}
//returneaza baza
int Numar::getBaza()
{
	return this->baza;
}
//setteri
//seteaza numarul cu noua valoare "n"
void Numar::setNumar(string n)
{
	this->numar = n;
}
//seteaza baza cu noua valoare "b"
void Numar::setBaza(int b)
{
	this->baza = b;
}
//Suprascrierea operatorului "="
Numar& Numar::operator=(const Numar& n)
{
	this->setNumar(n.numar);
	this->setBaza(n.baza);
	return *this;
}
//Suprascrierea operatorului "=="
//2 Numere sunt egale daca au aceeasi valoare atat pentru numar cat si pentru baza
bool Numar::operator==(const Numar& n)
{
	return (this->numar == n.numar) && (this->baza == n.baza);

}
//functia care va afisa Numarul in forma "Numarul: " ... si delimitator " Baza: "...
string Numar::toString(string delim)
{
	return "Numarul: "+numar + delim + " Baza: "+to_string(baza);

}
//Functia care realizeaza suma dintre 2 obiecte de tipul Numar
Numar Numar::suma(Numar b)
{
	int c1, c2, numar, t = 0;
	//c1-cifra primului numar
	//c2-cifra celui de al doilea numar
	//numar-nr obtinut prin adunarea celor 2 cifre
	//t-transportul
	string c3;//suma cifrei1+cifra2+transport in forma finala in functie de baza in care se afla
	string c4;//noul numar(pe dos)
	int ok = 0;
	int i = 0;
	int n = numara_cifre(*this);//cate cifre are a
	int m = numara_cifre(b);//cate cifre are b
	int cn = n;//copie n
	int cm = m;//copie m
	if (cn < cm)	//verificam cine are mai putine cifre
	{
		while (cn < cm)	//daca cn este mai mic decat cm
		{
			Numar z = inverseaza_numar(*this);//inversam numarul 
			string l = z.getNumar();//extragem numarul
			l.push_back('0');//inseram 0 la final
			z.setNumar(l);//setam cu noul numar la care am inserat 0
			*this = inverseaza_numar(z);//aducem numarul inapoi la forma initiala
			cn++;
		}
		//acum ambele numere au un numar egal de cifre
		m = cm;
		n = cn;
	}
	else
	{
		while (cm < cn)//daca cm este mai mic decat cn
		{
			Numar z = inverseaza_numar(b);//inversam numarul 
			string l = z.getNumar();//extragem numarul
			l.push_back('0');//inseram 0 la final
			z.setNumar(l);//setam cu noul numar la care am inserat 0
			b = inverseaza_numar(z);//aducem numarul inapoi la forma initiala
			cm++;
		}
		//acum ambele numere au un numar egal de cifre
		m = cm;
		n = cn;
	}
	while (n > 0 && m > 0)//cat timp nu s-a terminat numarul
	{
		//extragem din primul numar ultima cifra si o trasnformam in numar intreg din char
		if (((*this).getNumar().at(n - 1) >= 'A') && ((*this).getNumar().at(n - 1) <= 'F'))
			c1 = (*this).getNumar().at(n - 1) - 'A' + 10;//daca este litera
		else
			c1 = (*this).getNumar().at(n - 1) - '0';//daca este numar
		//extragem din al doilea numar ultima cifra si o trasnformam in numar intreg din char
		if ((b.getNumar().at(m - 1) >= 'A') && (b.getNumar().at(m - 1) <= 'F'))
			c2 = b.getNumar().at(m - 1) - 'A' + 10;//daca este litera
		else
			c2 = b.getNumar().at(m - 1) - '0';//daca este numar
		numar = c1 + c2 + t;//numarul obtinut
		if (numar >= 10 && numar <= 15)
			//daca acesta este intre 10 si 15
		{
			if (numar < (*this).getBaza())
			{	//daca este mai mic decat baza trebuie schimbat in litera
				c3 = numar - 10 + 'A';
				t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
			}
			else
			{	//in cazul in care este mai mare decat baza
				c3 = numar - (*this).getBaza() + '0';//se scade baza
				t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
			}
		}
		else
		{	//in cazul in care numarul este mai mare decat baza
			if (numar >= (*this).getBaza())
			{	//daca este mai mare decat baza trebuie scazuta baza din el
				c3 = numar - (*this).getBaza() + '0';//se scade baza
				t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
			}
			else
				//in cazul numarul este mai mic decat 9 si decat baza
				if (numar <= 9)
				{
					c3 = numar + '0';
					t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
				}
		}

		c4.insert(i, c3);//in stringul c4 se insereaza caracterul final
		i++;//creste pozitia
		//scad n si m
		n--;
		m--;

	}
	if ((i == cn) && (t != 0))//daca am ajuns la ultima cifra si transportul este diferit de 0 se va insera si acesta 
	{
		string tt;
		tt = t + '0';
		c4.insert(cn, tt);
	}
	Numar c(c4, (*this).getBaza());//se formeaza noul Numar cu baza si valoarea obtinuta
	Numar cc = inverseaza_numar(c);//se inverseaza rezultatul deoarece numerele au fost introduse invers
	return cc;//se returneaza rezultatul
}
Numar  Numar::diferenta( Numar b)
{
	int c1, c2, numar, t = 0;
	//c1-cifra primului numar
	//c2-cifra celui de al doilea numar
	//numar-nr obtinut prin adunarea celor 2 cifre
	//t-transportul
	string c3;
	string c5;
	string c4;
	int ok = 0;
	int i = 0;
	int n = numara_cifre(*this);//cate cifre are a
	int m = numara_cifre(b);//cate cifre are b
	int cn = n;
	int cm = m;
	if (((*this).getBaza() == b.getBaza()) && ((*this).getNumar() == b.getNumar()))//in cazul in care au aceeasi valoare se retuneaza 0 direct
	{
		Numar d("0", (*this).getBaza());
		return d;
	}
	else {
		if (cn < cm)
		{//daca cn este mai mic decat cm
			while (cn < cm)
			{
				Numar z = inverseaza_numar((*this));//inversam numarul 
				string l = z.getNumar();//extragem numarul
				l.push_back('0');//inseram 0 la final
				z.setNumar(l);//setam cu noul numar la care am inserat 0
				(*this) = inverseaza_numar(z);//aducem numarul inapoi la forma initiala
				cn++;
			}
			//acum ambele numere au un numar egal de cifre
			m = cm;
			n = cn;
		}
		else
		{
			while (cm < cn)//daca cm este mai mic decat cn
			{
				Numar z = inverseaza_numar(b);//inversam numarul 
				string l = z.getNumar();//extragem numarul
				l.push_back('0');//inseram 0 la final
				z.setNumar(l);//setam cu noul numar la care am inserat 0
				b = inverseaza_numar(z);//aducem numarul inapoi la forma initiala
				cm++;
			}
			//acum ambele numere au un numar egal de cifre
			m = cm;
			n = cn;
		}
		while (n > 0 && m > 0)//cat timp nu s-a terminat numarul
		{	//extragem din primul numar ultima cifra si o trasnformam in numar intreg din char
			int ok = 0;
			if (((*this).getNumar().at(n - 1) >= 'A') && ((*this).getNumar().at(n - 1) <= 'F'))
				c1 = (*this).getNumar().at(n - 1) - 'A' + 10;//daca este litera
			else
				c1 = (*this).getNumar().at(n - 1) - '0';//daca este numar
			//extragem din al doilea numar ultima cifra si o trasnformam in numar intreg din char
			if ((b.getNumar().at(m - 1) >= 'A') && (b.getNumar().at(m - 1) <= 'F'))
				c2 = b.getNumar().at(m - 1) - 'A' + 10;//daca este litera
			else
				c2 = b.getNumar().at(m - 1) - '0';//daca este numar
			numar = c1 - c2 + t;//numarul obtinut
			if (numar < 0)
			{	//daca numarul este negativ adaugam baza si setam ok=1
				numar = numar + (*this).getBaza();
				ok = 1;
			}
			if (numar >= 10 && numar <= 15)//daca acesta este intre 10 si 15

			{
				if (numar < (*this).getBaza())//daca este mai mic decat baza trebuie schimbat in litera
				{
					c3 = numar - 10 + 'A';
					t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
				}
				else
				{//in cazul in care este mai mare decat baza
					c3 = numar - (*this).getBaza() + '0';//se scade baza
					t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
				}
			}
			else
			{
				if (numar >= (*this).getBaza())
				{//in cazul in care numarul este mai mare decat baza
					c3 = numar - (*this).getBaza() + '0';//se scade baza
					t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
				}
				else
					//in cazul numarul este mai mic decat 9 si decat baza
					if (numar <= 9 && numar >= 0)
					{
						c3 = numar + '0';
						t = numar / (*this).getBaza();//noul transport este catul obtinut prin impartirea sumei la baza
					}
			}
			if (ok == 1)//daca ok=1 atunci transportul este negativ
				t = -1;
			c4.insert(i, c3);//in stringul c4 se insereaza caracterul final
			i++;
			n--;
			m--;

		}
		if ((i == cn) && (t != 0))//daca am ajuns la ultima cifra si transportul este diferit de 0 se va insera '-'
		{
			string tt = "-";
			c4.insert(cn, tt);
		}
		Numar c(c4, (*this).getBaza());
		Numar cc = inverseaza_numar(c);
		return cc;
	}
}
Numar Numar::inmultire( char b)
{

	int c1, c2, numar, t = 0;
	string c3;
	string c5;
	string c4;
	int ok = 0;
	int i = 0;
	int n = numara_cifre((*this));//cate cifre are a
	int cn = n;
	if (b == '0')//daca cifra este 0 se returneaza 0
	{
		Numar d("0", (*this).getBaza());
		return d;
	}
	while (n > 0)//cat timp nu s-a terminat numarul
	{//extragem din primul numar ultima cifra si o trasnformam in numar intreg din char
		int ok = 0;
		if (((*this).getNumar().at(n - 1) >= 'A') && ((*this).getNumar().at(n - 1) <= 'F'))
			c1 = (*this).getNumar().at(n - 1) - 'A' + 10;//daca este litera
		else
			c1 = (*this).getNumar().at(n - 1) - '0';//daca este numar
		//extragem din al doilea numar cifra si o trasnformam in numar intreg din char
		if ((b >= 'A') && (b <= 'F'))
			c2 = b - 'A' + 10;//daca este litera
		else
			c2 = b - '0';//daca este numar
		numar = c1 * c2 + t;//produsul
		if (numar > (*this).getBaza())
		{
			ok = numar / (*this).getBaza();//catul obtinut
			numar = numar % (*this).getBaza();//noul numar reprezinta restul impartirii la baza
		}
		//transformarea in litera corespunzatoare
		if (numar >= 10 && numar <= 15)

		{
			if (numar < (*this).getBaza())
			{
				c3 = numar - 10 + 'A';
				t = numar / (*this).getBaza();
			}
			else
			{
				c3 = numar - (*this).getBaza() + '0';
				t = numar / (*this).getBaza();
			}
		}
		else
		{
			if (numar >= (*this).getBaza())
			{
				c3 = numar - (*this).getBaza() + '0';
				t = numar / (*this).getBaza();
			}
			else
				if (numar <= 9)
				{
					c3 = numar + '0';
					t = numar / (*this).getBaza();
				}
		}
		if (ok != 0)
			t = ok;//restul 
		c4.insert(i, c3);//insereaza litera
		i++;
		n--;
	}
	if ((i == cn) && (t != 0))
	{
		string tt;
		tt = t + '0';//ultimul rest
		c4.insert(cn, tt);
	}
	Numar c(c4, (*this).getBaza());
	Numar cc = inverseaza_numar(c);
	return cc;
}
Numar Numar::impartire(char b)
{

	int c1, c2, numar, t = 0;
	string c3;
	string c5;
	string c4;
	int ok = 0;
	int i = 0;
	int n = numara_cifre((*this));//cate cifre are a
	int cn = n;
	if (b == '1')
	{

		return (*this);
	}
	Numar a = inverseaza_numar((*this));
	while (n > 0)
	{
		int ok = 0;
		if ((a.getNumar().at(n - 1) >= 'A') && (a.getNumar().at(n - 1) <= 'F'))
			c1 = a.getNumar().at(n - 1) - 'A' + 10;//daca este litera
		else
			c1 = a.getNumar().at(n - 1) - '0';//daca este numar
		if ((b >= 'A') && (b <= 'F'))
			c2 = b - 'A' + 10;//daca este litera
		else
			c2 = b - '0';//daca este numar
		numar = t * a.getBaza() + c1;//inmultirea transportului cu baza si adunarea cu cifra
		t = numar % c2;//noul transport
		numar = numar / c2;//noul numar
		if (numar > a.getBaza())
		{
			ok = numar % c2;//daca numarul este mai mare decat baza ,ok ia valoarea restului impartirii
		}
		//transformarea cifrei in litera
		if (numar >= 10 && numar <= 15)

		{
			if (numar < a.getBaza())
			{
				c3 = numar - 10 + 'A';

			}
			else
			{
				c3 = numar - a.getBaza() + '0';

			}
		}
		else
		{
			if (numar >= a.getBaza())
			{
				c3 = numar - a.getBaza() + '0';

			}
			else
				if (numar <= 9)
				{
					c3 = numar + '0';

				}
		}
		if (c3 != "0")//daca cifra este diferita de 0 se insereaza
		{
			c4.insert(i, c3);
			i++;
		}

		n--;
	}
	Numar c(c4, a.getBaza());
	return c;
}
Numar Numar::inmultire_cu_2_cifre(string b) {
	//functia realizeaza inmultirea unui numar cu un string cu 2 cifre
	if (b.size() == 1 && b.at(0) == '0')
	{
			Numar d("0", (*this).getBaza());
			return d;
	}
	Numar a1 = (*this).inmultire(b.at(1));//initial se inmulteste cu cifra unitatilor numarului "b"
	Numar a2= (*this).inmultire(b.at(0));//se inmulteste cu cifra zecilor
	Numar a3 = insereaza_0(a2);//se insereaza 0 la rezultatul inmultirii numarului cu cifra zecilor
	Numar a4 = a3.suma(a1);//se aduna cele 2 numere
	return a4;//se returneaza rezultattul	
}
Numar Numar::comparare(Numar b)
{	//compara 2 numere
	int n = numara_cifre((*this));//numarul de cifre de la primul numar
	int m = numara_cifre(b);//numarul de cifre de la al doilea numar
	if (n > m)
		return (*this);//returneaza obiectul
	else
	{
		if (n < m)
			return b;
		else
		{
			Numar c = inverseaza_numar((*this));
			Numar d = inverseaza_numar(b);
			int x = 0;//c>d
			int i = 0;//presupunem ca d este mai mare
			while (n>0&&x==0)
			{
				if (c.getNumar().at(n - 1) < d.getNumar().at(n - 1))
					x = 1;//d este mai mic
				n--;
			}
			if (x == 0)
				return c;
			else
				return d;

		}
	}

}