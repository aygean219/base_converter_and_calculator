//------------------//
//---NURLA AYGEAN---//
//------------------//
/*
In fisierul util se vor regasii toate functiile de conversie si alte functii folosite in operatiile efectuate.
*/
#pragma once
#include "numar.h"
#include "calcule.h"
int numara_cifre(Numar);
Numar inverseaza_numar(Numar a);
Numar insereaza_0(Numar a);
bool compara_baze(int baza1, string baza2);
Calcul impartire_cu_rest(Numar a,char b);
Numar conversie_impartiri_succesive(Numar a, string baza);
Numar conversie_substitutie(Numar a, string baza);
Calcul impartire_cu_rest_2(Numar a, string b);
Numar conversie_baza_intermediara(Numar a, string b);
Numar conversie_b4_in_b2(Numar a);
Numar conversie_b8_in_b2(Numar a);
Numar conversie_b16_in_b2(Numar a);
Numar conversie_b2_in_b4(Numar a);
Numar conversie_b2_in_b8(Numar a);
Numar conversie_b2_in_b16(Numar a);
