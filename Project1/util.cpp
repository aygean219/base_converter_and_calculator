//------------------//
//---NURLA AYGEAN---//
//------------------//
#include "numar.h"
#include "calcule.h"
#include <string.h>
#include <map>
#include <iostream> 
#include <iterator> 
using namespace std;

int numara_cifre(Numar a)
{	
	string aa= a.getNumar();//extrage numarul
	int n = aa.size();//afla lungimea
	return n;//o returneaza
}
Numar inverseaza_numar(Numar a)
{
	string nou;//noul string
	int n = numara_cifre(a);//numarul de cifre
	for (int i = n - 1; i >= 0; i--)
		nou.push_back(a.getNumar().at(i));//se ia de la finalul
	//lui a.getNumar() si se insereaza in nou
	a.setNumar(nou);//se seteaza noul numar
	return a;//se returneaza
}
Numar insereaza_0(Numar a)
{	string nou;
	int n = numara_cifre(a);
	for (int i = 0; i <n; i++)
		nou.push_back(a.getNumar().at(i));
	//se copiaza continutul in nou 
	nou.push_back('0');//si se insereaza 0 la final
	a.setNumar(nou);//se seteaza noul numar
	return a;//se returneaza
}
Calcul impartire_cu_rest(Numar aa,char b) {
	//are loc impartirea normala a numarului cu o cifra
	int c1, c2, numar, t = 0;
	string c3;
	string c5;
	string c4;
	int ok = 0;
	int i = 0;
	int restul=0;
	int n = numara_cifre(aa);//cate cifre are a
	int cn = n;
	if (b == '1')
	{

		return Calcul(aa.getNumar(),aa.getBaza(),0);
	}
	Numar a = inverseaza_numar(aa);
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
		numar = t * a.getBaza() + c1;
		t = numar % c2;
		numar = numar / c2;
		if (numar > a.getBaza())
		{
			ok = numar % c2;
		}
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
		if (c3 != "0")
		{
			c4.insert(i, c3);
			i++;
		}
		if (c3 == "0"&&i != 0)
		{
			c4.insert(i, c3);
			i++;
		}
		restul = t;//se pastreaza restul 
		n--;
	}

	Calcul c(c4, a.getBaza(), restul);//se formeaza un Calcul cu numarul rezultat 
	//si restul obtinut
	return c;
}

Calcul impartire_cu_rest_2(Numar aa, string b) {
	//are loc impartirea numarului cu 2 cifre
	int c1, c2, numar, t = 0;
	string c3;
	string c5;
	string c4;
	int ok = 0;
	int i = 0;
	int restul = 0;
	int n = numara_cifre(aa);//cate cifre are a
	int cn = n;
	if (b.size() == 1 && b.at(0) == '1')
	{

		return Calcul(aa.getNumar(), aa.getBaza(), 0);
	}
	Numar a = inverseaza_numar(aa);
	while (n > 0)
	{
		int ok = 0;
		if ((a.getNumar().at(n - 1) >= 'A') && (a.getNumar().at(n - 1) <= 'F'))
			c1 = a.getNumar().at(n - 1) - 'A' + 10;//daca este litera
		else
			c1 = a.getNumar().at(n - 1) - '0';//daca este numar
		if ((b.size() == 2) && (b.at(0) == '1') && (b.at(1) <= '6'))
			c2 = 10 + b.at(1) - '0';
		else
			c2 = b.at(0) - '0';
		numar = t * a.getBaza() + c1;
		t = numar % c2;
		numar = numar / c2;
		if (numar > a.getBaza())
		{
			ok = numar % c2;
		}
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
		if(c3!="0")
			{
				c4.insert(i, c3);
				i++;
			}
		if(c3=="0"&&i!=0)
		{
			c4.insert(i, c3);
			i++;
		}
		restul = t;
		n--;
	}
	Calcul c(c4, a.getBaza(), restul);
	return c;
}
Numar conversie_impartiri_succesive(Numar a, string baza)
{
	string baza1;
	int baza_new;
	if ((baza.size() == 2) && (baza.at(0) == '1') && (baza.at(1) <= '6'))
		baza_new = 10 + baza.at(1) - '0';
	else
		baza_new = baza.at(0) - '0';
	string nr;
	int i = 0;
	while (a.getNumar() != "")
	{
		Calcul b = impartire_cu_rest_2(a, baza);//de fiecare data se va imparti numarul
		//si se va pastra restul
		string caracter;
		if (baza.size() == 2&&b.getTransport()>=10) //daca are 2 cifre baza si transportul
			//este mai mare decat 10
			//se va converti in litera corespunzatoare
		{	string baza_string, baza_string1;
			baza_string.insert(0, "1");
			baza_string1 = baza.at(1) - 10 + '0';
			baza_string.insert(1, baza_string1);//se converteste numarul din int in litera corespunzatoare
			map<int, string> c;
			c.insert(pair<int, string>(10, "A"));
			c.insert(pair<int, string>(11, "B"));
			c.insert(pair<int, string>(12, "C"));
			c.insert(pair<int, string>(13, "D"));
			c.insert(pair<int, string>(14, "E"));
			c.insert(pair<int, string>(15, "F"));
			map<int, string>::iterator itr;
			for (itr = c.begin(); itr != c.end(); ++itr)
			{
				if (itr->first == b.getTransport())
				{
					baza1 = itr->second;
				}
			}
			caracter = baza1;
		}
		else { caracter = b.getTransport() + '0'; }//are o cifra 
		nr.insert(i, caracter);//se insereaza
		a.setBaza(b.getBaza());//se seteaza baza
		a.setNumar(b.getNumar());//se seteaza numarul
		i++;
	}
	Numar new_a(nr, baza_new);//se obtine noul numar format din resturi
	a = inverseaza_numar(new_a);//se inverseaza
	return a;

}

Numar conversie_substitutie(Numar a, string baza)
{
	
	Numar b = inverseaza_numar(a);
	int n = numara_cifre(b);
	int baza_nr;
	if ((baza.size() == 2) && (baza.at(0) == '1') && (baza.at(1) <= '6'))
		baza_nr = 10 + baza.at(1) - '0';
	else
		baza_nr = baza.at(0) - '0';
	Numar nr("0", baza_nr);
	char baza_char;
	if (b.getBaza()<=9)//baza de la 2 la 9,baza in care se afla numarul
	{
		//de fiecare data numarul vechi se va aduna cu cifra curenta 
		//si se va inmulti cu baza sa
		while (n > 0)
		{
			string numar1;
			numar1 = b.getNumar().at(n - 1);
			Numar nr1(numar1, baza_nr);
			Numar suma = nr1.suma(nr);
			baza_char = b.getBaza() + '0';
			Numar produs = suma.inmultire(baza_char);
			if (n > 1)
				nr = produs;//daca nu s-a ajuns la ultima cifra 
			//noul numar va fii egal cu produs
			else
				nr = suma;//in cazul in care se afla la ultima cifra atunci el
			//va fii egal cu suma ,deoarece nu mai e nevoie sa se inmulteasca cu 
			n--;
		}
	}
	else
	{
		//baza este mai mare decat 9 ,baza in care se afla numarul
		while (n > 0)
		{
			char baza_char2;
			string numar1;
			Numar nr1, suma, produs;
			if (baza_nr >= 10) {//baza la care se converteste
				//se converteste in litera corespunzatoare
				string baza_string;
				baza_string.insert(0, "1");
				string baza_string1;
				baza_string1 = b.getBaza() - 10 + '0';
				baza_string.insert(1, baza_string1);
				map<char, string> c;
				c.insert(pair<char, string>('A', "10"));
				c.insert(pair<char, string>('B', "11"));
				c.insert(pair<char, string>('C', "12"));
				c.insert(pair<char, string>('D', "13"));
				c.insert(pair<char, string>('E', "14"));
				c.insert(pair<char, string>('F', "15"));
				map<char, string>::iterator itr;
				for (itr = c.begin(); itr != c.end(); ++itr)
				{
					if (itr->second == baza_string)
					{
						baza_char2 = itr->first;
					}
				}
				//de fiecare data numarul vechi se va aduna cu cifra curenta 
				//si se va inmulti cu baza sa
				numar1 = b.getNumar().at(n - 1);
				Numar nr1(numar1, baza_nr);
				suma = nr1.suma(nr);
				produs = suma.inmultire(baza_char2);
				if (n > 1)
					nr = produs;//daca nu s-a ajuns la ultima cifra 
				//noul numar va fii egal cu produs
				else
					nr = suma;//in cazul in care se afla la ultima cifra atunci el
				//va fii egal cu suma ,deoarece nu mai e nevoie sa se inmulteasca cu 
				n--;
			}
			else
			{	//baza in care se converteste ,este mai mica decat 9
				numar1 = b.getNumar().at(n - 1);
				Numar nr1(numar1, baza_nr);
				 suma = nr1.suma(nr);
				 produs = suma.inmultire_cu_2_cifre(baza);
				 if (n > 1)
					 nr = produs;//daca nu s-a ajuns la ultima cifra 
				 //noul numar va fii egal cu produs
				 else
					 nr = suma;//in cazul in care se afla la ultima cifra atunci el
				 //va fii egal cu suma ,deoarece nu mai e nevoie sa se inmulteasca cu 
				n--;
			}
		}
	}
	return nr;
}
Numar conversie_baza_intermediara(Numar a, string b)
{	
	string baza_string;
	int n = b.size();
	string baza_string1;
	Numar c, d;
	int baza1=0;//transform b in numar
	if (n == 1)
	{	
		baza1 = b.at(0) - '0';//baza este formata dintr un numar
	}
	else
	{		//este format din 2 cifre
			baza_string.insert(0, "1");
			baza_string1 = b.at(1) - 10 + '0';
			baza_string.insert(1, baza_string1);
			map<int, string> c;
			c.insert(pair<int, string>(10, "10"));
			c.insert(pair<int, string>(11, "11"));
			c.insert(pair<int, string>(12, "12"));
			c.insert(pair<int, string>(13, "13"));
			c.insert(pair<int, string>(14, "14"));
			c.insert(pair<int, string>(15, "15"));
			map<int, string>::iterator itr;
			for (itr = c.begin(); itr != c.end(); ++itr)
			{
				if (itr->second == baza_string)
				{
					baza1 = itr->first;
				}
			}
	}
	//baza finala s a convertit in int
		if (a.getBaza() < 10)
		{	//daca baza initiala este mai mica decat 10
			//se va folosi converia prin substitutie
			c = conversie_substitutie(a, "10");
			if (10 < baza1)
			{
			//daca baza 10 este mai mica decat baza finala
			//se va folosi converia prin substitutie
				d = conversie_substitutie(c, b);
			}
			else
			{	//daca baza 10 este mai mare decat baza finala
			//se va folosi converia prin impartire
				d = conversie_impartiri_succesive(c, b);
			}
		}
		else
		{	//daca baza initiala este mai mare decat 10
			//se va folosi converia prin impartire
			 c = conversie_impartiri_succesive(a, "10");
			if (10 < baza1)
			{	//daca baza 10 este mai mica decat baza finala
			//se va folosi converia prin substitutie
				d = conversie_substitutie(c, b);
			}
			else
			{//daca baza 10 este mai mare decat baza finala
			//se va folosi converia prin impartire
				d = conversie_impartiri_succesive(c, b);
			}
		}
		return d;
}
Numar conversie_b4_in_b2(Numar a)
{	
	Numar c("", 2);
	string d;
	int nr = 0;
	//la fiecare numar din baza 4 i se asociaza 2 cifre in baza 2
	map<int, string> b;
	b.insert(pair<int,string>(0, "00"));
	b.insert(pair<int, string>(1, "01"));
	b.insert(pair<int, string>(2, "10"));
	b.insert(pair<int, string>(3, "11"));
	map<int,string>::iterator itr;
	int n = numara_cifre(a);
 		for (int i = 0; i< n; i++)
		{
			for (itr = b.begin(); itr != b.end(); ++itr)
			{
			string m = a.getNumar();
			int n = m.at(i)-'0';//transformarea cifrei in int
			if (itr->first == n)
			{
				d.insert(nr*2, itr->second);//adaugarea cifrelor din baza 2 
				nr++;
			}
			}
			
		}
		
	
	c.setNumar(d);
	return c;
}
Numar conversie_b2_in_b4(Numar a)
{
	Numar c("", 4);
	string d;
	int nr = 0;
	//la fiecare 2 cifre din baza 2 i se asociaza 1 cifra in baza 4
	map< string, int> b;
	b.insert(pair<string, int>("00",0));
	b.insert(pair<string, int>("01",1));
	b.insert(pair<string, int>("10",2));
	b.insert(pair<string, int>("11",3));
	map<string, int>::iterator itr;
	int n = numara_cifre(a);
	for (int i = 0; i < n; i=i+2)
	{
		int ok = 0;
		for (itr = b.begin(); itr != b.end() && ok == 0; ++itr)
		{
			string m = a.getNumar();
			char m1 = m.at(i);//prima cifra din baza 2
			char m2 = m.at(i+1);//a doua cifra din baza 2
			string m3;
			m3.push_back(m1);
			m3.push_back(m2);
			
			if (itr->first == m3)
			{
				string n;
				n=itr->second + '0';//formare numar in baza 4
				d.insert(nr, n);//inserare numar
				nr++;
				ok = 1;
			}
		}

	}
	c.setNumar(d);
	return c;
}
Numar conversie_b8_in_b2(Numar a)

{
	//la fiecare numar din baza 8 i se asociaza 3 cifre in baza 2
	Numar c("", 2);
	string d;
	int nr = 0;
	map<int, string> b;
	b.insert(pair<int, string>(0, "000"));
	b.insert(pair<int, string>(1, "001"));
	b.insert(pair<int, string>(2, "010"));
	b.insert(pair<int, string>(3, "011"));
	b.insert(pair<int, string>(4, "100"));
	b.insert(pair<int, string>(5, "101"));
	b.insert(pair<int, string>(6, "110"));
	b.insert(pair<int, string>(7, "111"));
	map<int, string>::iterator itr;
	int n = numara_cifre(a);
	for (int i = 0; i < n; i++)
	{
		int ok = 0;
		for (itr = b.begin(); itr != b.end() && ok == 0; ++itr)
		{
			string m = a.getNumar();
			int n = m.at(i) - '0';//transformarea cifrei in int
			if (itr->first == n)
			{
				d.insert(nr * 3, itr->second);//adaugarea cifrelor din baza 2 
				nr++;
				ok = 1;
			}
		}

	}


	c.setNumar(d);
	return c;
}
Numar conversie_b2_in_b8(Numar a)
{	//la fiecare 3 cifre din baza 2 i se asociaza 1 cifra in baza 8
	Numar c("", 8);
	string d;
	int nr = 0;
	map< string, int> b;
	b.insert(pair<string, int>("000", 0));
	b.insert(pair<string, int>("001", 1));
	b.insert(pair<string, int>("010", 2));
	b.insert(pair<string, int>("011", 3));
	b.insert(pair<string, int>("100", 4));
	b.insert(pair<string, int>("101", 5));
	b.insert(pair<string, int>("110", 6));
	b.insert(pair<string, int>("111", 7));
	map<string, int>::iterator itr;
	int n = numara_cifre(a);
	for (int i = 0; i < n; i=i+3)
	{
		int ok = 0;
		for (itr = b.begin(); itr != b.end() && ok == 0; ++itr)
		{
			string m = a.getNumar();
			char m1 = m.at(i);//prima cifra din baza 2
			char m2 = m.at(i + 1);//a doua cifra din baza 2
			char m3 = m.at(i+ 2);//a treia cifra din baza 2
			string mm;
			mm.push_back(m1);
			mm.push_back(m2);
			mm.push_back(m3);
			if (itr->first == mm)
			{
				string n;
				n = itr->second + '0';//numarul in baza 8
				d.insert(nr, n);//inserare numar
				nr++;
				ok = 1;
			}
		}

	}
	c.setNumar(d);//setarea numarului
	return c;
}
Numar conversie_b16_in_b2(Numar a)

{
	//la fiecare numar din baza 16 i se asociaza 4 cifre in baza 2
	Numar c("", 2);
	string d;
	int nr = 0;
	map<string, string> b;
	b.insert(pair<string, string>("0", "0000"));
	b.insert(pair<string, string >("1", "0001"));
	b.insert(pair<string, string >("2", "0010"));
	b.insert(pair<string, string > ("3", "0011"));
	b.insert(pair<string, string>("4", "0100"));
	b.insert(pair<string, string>("5", "0101"));
	b.insert(pair<string, string>("6", "0110"));
	b.insert(pair<string, string>("7", "0111"));
	b.insert(pair<string, string>("8", "1000"));
	b.insert(pair<string, string>("9", "1001"));
	b.insert(pair<string, string>("A", "1010"));
	b.insert(pair<string, string>("B", "1011"));
	b.insert(pair<string, string>("C", "1100"));
	b.insert(pair<string, string>("D", "1101"));
	b.insert(pair<string, string>("E", "1110"));
	b.insert(pair<string, string>("F", "1111"));
	map<string, string>::iterator itr;
	int n = numara_cifre(a);
	for (int i = 0; i < n; i++)
	{
		int ok = 0;
		for (itr = b.begin(); itr != b.end() && ok == 0; ++itr)
		{
			string m = a.getNumar();
			string n;
			n= m.at(i);
			if (itr->first == n)
			{
				d.insert(nr * 4, itr->second);//adaugarea cifrelor din baza 2 
				nr++;
				ok = 1;
			}
		}

	}


	c.setNumar(d);
	return c;
}
Numar conversie_b2_in_b16(Numar a)
{		//la fiecare 4 cifre din baza 2 i se asociaza 1 cifra in baza 16
	Numar c("", 16);
	string d;
	int nr = 0;
	map<string, string> b;
	b.insert(pair<string, string>("0000","0"));
	b.insert(pair<string, string >("0001","1"));
	b.insert(pair<string, string >("0010","2"));
	b.insert(pair<string, string >("0011","3"));
	b.insert(pair<string, string>("0100","4"));
	b.insert(pair<string, string>("0101","5"));
	b.insert(pair<string, string>("0110","6"));
	b.insert(pair<string, string>("0111","7"));
	b.insert(pair<string, string>("1000","8"));
	b.insert(pair<string, string>("1001","9"));
	b.insert(pair<string, string>("1010","A"));
	b.insert(pair<string, string>("1011","B"));
	b.insert(pair<string, string>("1100","C"));
	b.insert(pair<string, string>("1101","D"));
	b.insert(pair<string, string>("1110","E"));
	b.insert(pair<string, string>("1111","F"));
	map<string, string>::iterator itr;
	int n = numara_cifre(a);
	for (int i = 0; i < n; i = i + 4)
	{
		int ok = 0;
		for (itr = b.begin(); itr != b.end() && ok == 0; ++itr)
		{
			string m = a.getNumar();
			char m1 = m.at(i);//prima cifra din baza 2
			char m2 = m.at(i + 1);//a doua cifra din baza 2
			char m3 = m.at(i + 2);//a treia cifra din baza 2
			char m4 = m.at(i + 3);//a patra cifra din baza 2
			string mm;
			mm.push_back(m1);
			mm.push_back(m2);
			mm.push_back(m3);
			mm.push_back(m4);
			if (itr->first == mm)
			{
				string n;
				n = itr->second;//n ia valoarea cifrei din baza 16
				d.insert(nr, n);//inserare numar in baza 16
				nr++;
				ok = 1;
			}
		}

	}
	c.setNumar(d);//setare cu noul numar
	return c;
}
bool compara_baze(int baza1, string baza2)
{	//true-daca prima este mai mare
	//false-daca prima este mai mica
	
	int baza11;
	if (baza2.size() == 2) {
		//in cazul in care baza este format din 2 cifre
		string baza_string, baza_string1;
		baza_string.insert(0, "1");
		baza_string1 = baza2.at(1) - 10 + '0';
		baza_string.insert(1, baza_string1);
		map<int, string> c;
		c.insert(pair<int, string>(10, "10"));
		c.insert(pair<int, string>(11, "11"));
		c.insert(pair<int, string>(12, "12"));
		c.insert(pair<int, string>(13, "13"));
		c.insert(pair<int, string>(14, "14"));
		c.insert(pair<int, string>(15, "15"));
		c.insert(pair<int, string>(16, "16"));
		map<int, string>::iterator itr;
		for (itr = c.begin(); itr != c.end(); ++itr)
		{
			if (itr->second == baza_string)
			{
				baza11 = itr->first;
			}
		}
	}
	else
	{
		baza11 = baza2.at(0) - '0';
	}
	if (baza1 < baza11)
		return true;
	else
		return false;

}
