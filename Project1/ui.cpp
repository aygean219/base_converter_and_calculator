//------------------//
//---NURLA AYGEAN---//
//------------------//
#include "ui.h"
#include"numar.h"
#include "util.h"
#include"calcule.h"
#include<iostream>
#include <string.h>

void UI::meniu_principal()
{

	cout << "0.Oprire program" << endl;
	cout << "1.Conversie prin impartiri succesive." << endl;
	cout << "2.Conversie prin substitutie." << endl;
	cout << "3.Conversie folosind baza intermediara 10." << endl;
	cout << "4.Conversii rapide:din baza 2 in baza 4." << endl;
	cout << "5.Conversii rapide:din baza 2 in baza 8." << endl;
	cout << "6.Conversii rapide:din baza 2 in baza 16." << endl;
	cout << "7.Conversii rapide:din baza 4 in baza 2." << endl;
	cout << "8.Conversii rapide:din baza 8 in baza 2." << endl;
	cout << "9.Conversii rapide:din baza 16 in baza 2." << endl;
	cout << "10.Adunarea a 2 a numere." << endl;
	cout << "11.Scaderea a 2 a numere." << endl;
	cout << "12.Inmultirea unui numar cu o cifra." << endl;
	cout << "13.Impartirea unui numar cu o cifra." << endl;
}
void UI::conversii_impartire_succesive()
{
	cout << "Dati numarul pe care doriti sa-l convertiti impreuna cu baza in care se afla" << endl ;
	cout << "!!!Atentie se poate converti doar dintr-o baza mai MARE intr-o baza mai MICA!!!" << endl << "Numar:";
	string nr;
	int baza;
	string baza_noua;
	//se verifica daca baza initiala mai mare decat baza finala
	try {
		cin >> nr;
		cout << endl << "Baza:";
		cin >> baza;
		cout << "Dati noua baza a numarului " << nr << ": ";
		cin >> baza_noua;
		bool c = compara_baze(baza, baza_noua);
		//true--- baza<baza_noua
		if (c == true)
			throw " Baza initiala este mai MICA decat baza finala!!";
		Numar n(nr, baza);
		Numar nr_nou = conversie_impartiri_succesive(n, baza_noua);
		cout << "=>" << nr_nou.toString(";") << endl;
	}
	//daca nu este mai mare se prezinta eroarea
	catch (const char* msg)
	{
		cout << "ERROR:" << msg << endl;
	}
	
	
}
void UI::conversii_baza_intermediara()
{
	cout << "Dati numarul pe care doriti sa-l convertiti impreuna cu baza in care se afla" << endl << "Numar:";
	string nr;
	cin >> nr;
	cout << endl << "Baza:";
	int baza;
	cin >> baza;
	cout << "Dati noua baza a numarului " << nr << ": ";
	string baza_noua;
	cin >> baza_noua;
	Numar n(nr, baza);
	Numar nr_nou = conversie_baza_intermediara(n, baza_noua);
	cout << "=>" << nr_nou.toString(";") << endl;
}
void UI::conversii_substitutie()
{
	cout << "Dati numarul pe care doriti sa-l convertiti impreuna cu baza in care se afla" << endl << "Numar:";
	cout << "!!!Atentie se poate converti doar dintr-o baza mai MICA intr-o baza mai MARE!!!" << endl << "Numar:";
	string nr;
	int baza;
	string baza_noua;
	try {
		cin >> nr;
		cout << endl << "Baza:";
		cin >> baza;
		cout << "Dati noua baza a numarului " << nr << ": ";
		cin >> baza_noua;
		bool c = compara_baze(baza, baza_noua);
		//true--- baza<baza_noua
		if (c != true)
			throw " Baza initiala este mai MARE decat baza finala!!";
		Numar n(nr, baza);
		Numar nr_nou = conversie_substitutie(n, baza_noua);
		cout << "=>" << nr_nou.toString(";") << endl;
	}
	catch (const char* msg)
	{
		cout << "ERROR:" << msg << endl;
	}
}
void UI::conversii_b2_in_b4()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 2 in baza 4" << endl ;
	cout << "La fiecare 2 cifre din baza 2 ii corespunde 1 cifra in baza 4." << endl << "Numar:";
	string nr;
	try {
		cin >> nr;
		Numar n(nr, 2);
		if (nr.size() % 2 != 0)//arunca exceptie daca in loc de 01 se introduce 1
			throw "Nu ati introdus un numar corect!La fiecare 2 cifre din baza 2 ii corespunde 1 cifra in baza 4.";
		Numar nr_nou = conversie_b2_in_b4(n);
		cout << "=>" << nr_nou.toString(";") << endl;
	}
	catch (const char* msg)
	{
		cout << "ERROR:" << msg << endl;
	}
}
void UI::conversii_b2_in_b8()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 2 in baza 8" << endl;
	cout << "La fiecare 3 cifre din baza 2 ii corespunde 1 cifra in baza 8." << endl << "Numar:";
	string nr;
	try {
		cin >> nr;
		if (nr.size() % 3 != 0)//arunca exceptie daca in loc de 001 se introduce 1
			throw "Nu ati introdus un numar corect!La fiecare 3 cifre din baza 2 ii corespunde 1 cifra in baza 8.";
		Numar n(nr, 8);
		Numar nr_nou = conversie_b2_in_b8(n);
		cout << "=>" << nr_nou.toString(";") << endl;
	}
	catch (const char* msg)
	{
		cout << "ERROR:" << msg << endl;
	}
}
void UI::conversii_b2_in_b16()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 2 in baza 16" << endl ;
	cout << "La fiecare 4 cifre din baza 2 ii corespunde 1 cifra in baza 16." << endl << "Numar:";
	string nr;
	try {
		cin >> nr;
		if (nr.size() % 4 != 0)//arunca exceptie daca in loc de 0001 se introduce 1
			throw "Nu ati introdus un numar corect!La fiecare 4 cifre din baza 2 ii corespunde 1 cifra in baza 16.";
		Numar n(nr, 16);
		Numar nr_nou = conversie_b2_in_b16(n);
		cout << "=>" << nr_nou.toString(";") << endl;
	}
	catch (const char* msg)
	{
		cout << "ERROR:" << msg << endl;
	}
}
void UI::conversii_b4_in_b2()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 4 in baza 2" << endl << "Numar:";
	string nr;
	cin >> nr;
	Numar n(nr, 4);
	Numar nr_nou = conversie_b4_in_b2(n);
	cout << "=>" << nr_nou.toString(";") << endl;

}
void UI::conversii_b8_in_b2()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 8 in baza 2" << endl << "Numar:";
	string nr;
	cin >> nr;
	Numar n(nr, 8);
	Numar nr_nou = conversie_b8_in_b2(n);
	cout << "=>" << nr_nou.toString(";") << endl;
}
void UI::conversii_b16_in_b2()
{
	cout << "Dati numarul pe care doriti sa-l convertiti din baza 16 in baza 2" << endl << "Numar:";
	string nr;
	cin >> nr;
	Numar n(nr, 16);
	Numar nr_nou = conversie_b16_in_b2(n);
	cout << "=>" << nr_nou.toString(";") << endl;
}
void UI::adunare()
{
	cout << "Dati primul numar pe care doriti sa-l adunati si baza acestuia!" << endl << "Numar:";
	string nr1, nr2;
	int baza1, baza2;
	cin >> nr1;
	cout << "Baza:";
	cin >> baza1;
	cout << "Dati al doilea numar pe care doriti sa-l adunati:" << endl << "Numar: ";
	cin >> nr2;
	cout << "Baza:";
	cin >> baza2;
	cout << "Doriti rezultatul in alta baza?" << endl << "1.Da" << endl << "2.Nu" << endl;
	int optiune = 0;
	Numar n1(nr1, baza1);
	Numar n2(nr2, baza2);
	string baza;
	cin >> optiune;
	if (optiune == 1)
	{
		cout << "Dati baza in care doriti sa fie rezultatul: ";
		cin >> baza;
		Numar a = conversie_baza_intermediara(n1, baza);
		Numar b = conversie_baza_intermediara(n2, baza);
		Numar c = a.suma(b);
		cout << "S-a obtinut rezultatul: " <<endl<< c.toString(";") << endl;
	}
	else
	{
		if (baza1 == baza2)
		{
			Numar d = n1.suma(n2);
			cout << "S-a obtinut rezultatul: " << endl << d.toString(";") << endl;
		}
		else
		{
			cout << "Cele doua numere au baza diferita,nu se pot aduna!" << endl;
		}
	}
}
void UI::scadere()
{
	cout << "Dati primul numar din care doriti sa scadeti si baza acestuia!!" << endl <<"!!ATENTIE!! acesta trebuie sa fie mai mare decat al doilea"<< "Numar:";
	string nr1, nr2;
	int baza1, baza2;
	cin >> nr1;
	cout << "Baza:";
	cin >> baza1;
	cout << "Dati al doilea numar pe care doriti sa-l scadeti:" << endl << "Numar: ";
	cin >> nr2;
	cout << "Baza:";
	cin >> baza2;
	cout << "Doriti rezultatul in alta baza?" << endl << "1.Da" << endl << "2.Nu" << endl;
	int optiune = 0;
	Numar n1(nr1, baza1);
	Numar n2(nr2, baza2);
	string baza;
	cin >> optiune;
	if (optiune == 1)
	{
		cout << "Dati baza in care doriti sa fie rezultatul: ";
		cin >> baza;
		Numar a = conversie_baza_intermediara(n1, baza);
		Numar b = conversie_baza_intermediara(n2, baza);
		Numar c = a.diferenta(b);
		cout << "S-a obtinut rezultatul: " << endl << c.toString(";") << endl;
	}
	else
	{
		if (baza1 == baza2)
		{
			Numar d = n1.diferenta(n2);
			cout << "S-a obtinut rezultatul: " << endl << d.toString(";") << endl;
		}
		else
		{
			cout << "Cele doua numere au baza diferita,nu se pot scadea!" << endl;
		}
	}
}
void UI::inmultire()
{
	cout << "Dati primul numar pe care doriti sa-l inmultitit si baza acestuia!!" << endl << "Numar:";
	string nr1;
	int baza1;
	cin >> nr1;
	cout << "Baza:";
	cin >> baza1;
	char b;
	cout << "Dati cifra cu care doriti sa-l inmultiti:"<<endl;
	cin >> b;
	cout << "Doriti rezultatul in alta baza?" << endl << "1.Da" << endl << "2.Nu" << endl;
	int optiune = 0;
	Numar n1(nr1, baza1);
	string baza;
	cin >> optiune;
	if (optiune == 1)
	{
		cout << "Dati baza in care doriti sa fie rezultatul: ";
		cin >> baza;
		Numar a = conversie_baza_intermediara(n1, baza);
		Numar c = a.inmultire(b);
		cout << "S-a obtinut rezultatul: " << endl << c.toString(";") << endl;
	}
	else
	{
			Numar d = n1.inmultire(b);
			cout << "S-a obtinut rezultatul: " << endl << d.toString(";") << endl;
	}
}
void UI::impartire()
{
	cout << "Dati primul numar pe care doriti sa-l impartiti si baza acestuia!!" << endl << "Numar:";
	string nr1;
	int baza1;
	cin >> nr1;
	cout << "Baza:";
	cin >> baza1;
	char b;
	cout << "Dati cifra cu care doriti sa-l impartiti:" << endl;
	cin >> b;
	cout << "Doriti rezultatul in alta baza?" << endl << "1.Da" << endl << "2.Nu" << endl;
	int optiune=0;
	Numar n1(nr1, baza1);
	string baza;
	cin >> optiune;
	if (optiune == 1)
	{
		cout << "Dati baza in care doriti sa fie rezultatul: ";
		cin >> baza;
		Numar a = conversie_baza_intermediara(n1, baza);
		Numar c = a.impartire(b);
		cout << "S-a obtinut rezultatul: " << endl << c.toString(";") << endl;
	}
	else
	{
		Numar d = n1.impartire(b);
		cout << "S-a obtinut rezultatul: " << endl << d.toString(";") << endl;
	}
}
void UI::showMenu()
{
	bool gata = false;
	while (!gata)
	{
		meniu_principal();
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1: {conversii_impartire_succesive(); break; }
		case 2: {conversii_substitutie(); break; }
		case 3: {conversii_baza_intermediara(); break; }
		case 4: {conversii_b2_in_b4(); break; }
		case 5: {conversii_b2_in_b8(); break; }
		case 6: {conversii_b2_in_b16(); break; }
		case 7: {conversii_b4_in_b2(); break; }
		case 8: {conversii_b8_in_b2(); break; }
		case 9: {conversii_b16_in_b2(); break; }
		case 10: {adunare(); break; }
		case 11: {scadere(); break; }
		case 12: {inmultire(); break; }
		case 13: {impartire(); break; }
		case 0: { gata = true;  }
		}
	}
}
