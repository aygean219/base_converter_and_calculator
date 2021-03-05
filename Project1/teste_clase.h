//------------------//
//---NURLA AYGEAN---//
//------------------//
/*
Clasa Teste este o clasa realizata pentru a testa toate procesele ce au loc.
Toate functiile private vor fii apelate in functia publica testClase().
*/
#pragma once
#include"numar.h"
#include "util.h"
#include"calcule.h"
class Teste {
private:
	void test_numar();
	void test_calcul();
	void test_adunare();
	void test_diferenta();
	void test_inmultire();
	void test_impartire();
	void test_impartire_rest();
	void test_nr_cif();
	void test_inverseaza();
	void test_conversie_impartiri_succesive();
	void test_conversie_baza_intermediara();
	void test_conversie_substitutie();
	void test_conversie_b4_in_b2();
	void test_conversie_b8_in_b2();
	void test_conversie_b16_in_b2();
	void test_conversie_b2_in_b4();
	void test_conversie_b2_in_b8();
	void test_conversie_b2_in_b16();
public:
	void testClase();
};