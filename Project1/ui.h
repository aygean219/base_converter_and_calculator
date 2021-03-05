//------------------//
//---NURLA AYGEAN---//
//------------------//
/*
Clasa UI pune la dispozitie utilizatorului meniul si toate functionalitatile de conversie si de calcul.
*/
#pragma once
#include <string>
using namespace std;
class UI {
private:
	void meniu_principal();
	void meniu_conversii();
	void meniu_conversii_rapide();
	void meniu_calcule();
	void meniu__conversii();
	void meniu__calcule();
	void conversii_impartire_succesive();
	void conversii_substitutie();
	void conversii_baza_intermediara();
	void conversii_b2_in_b4();
	void conversii_b2_in_b8();
	void conversii_b2_in_b16();
	void conversii_b4_in_b2();
	void conversii_b8_in_b2();
	void conversii_b16_in_b2();
	void adunare();
	void inmultire();
	void scadere();
	void impartire();
public:
//	UI();
	//~UI();
	void showMenu();

};