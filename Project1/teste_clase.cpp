//------------------//
//---NURLA AYGEAN---//
//------------------//
#include"teste_clase.h"
#include<iostream>
#include <assert.h>
#include <string.h>
void Teste::test_nr_cif()
{
	Numar n("AB12", 16);
	int nr = numara_cifre(n);
	assert(nr == 4);
}
void Teste::test_inverseaza()
{
	Numar n("AB12", 16);
	Numar nr = inverseaza_numar(n);
	assert((nr.getBaza() == 16) && (nr.getNumar() == "21BA"));
}
void Teste::test_numar()
{
	Numar n("AB12", 16);
	assert((n.getBaza() == 16) && (n.getNumar() == "AB12"));
	n.setBaza(12);
	n.setNumar("10");
	assert((n.getBaza() == 12) && (n.getNumar() == "10"));
}
void Teste::test_calcul()
{
	Calcul n("AB12", 16, 0);
	assert((n.getBaza() == 16) && (n.getNumar() == "AB12")&&(n.getTransport()==0));
	n.setTransport(1);
	assert((n.getBaza() == 16) && (n.getNumar() == "AB12") && (n.getTransport() == 1));
}
void Teste::test_adunare()
{
	Numar n1("123", 4);
	Numar n2("12", 4);
	Numar n = n1.suma(n2);
	assert((n.getBaza() == 4) && (n.getNumar() == "201"));
	Numar n3("1A", 16);
	Numar n4("12",16);
	Numar n5 = n3.suma( n4);
	assert((n5.getBaza() == 16) && (n5.getNumar() == "2C"));
	Numar n6("1A29", 11);
	Numar n7("12A", 11);
	Numar n8 = n6.suma( n7);
	assert((n8.getBaza() == 11) && (n8.getNumar() == "2058"));
	Numar n9("101", 2);
	Numar n10("101", 2);
	Numar n11 = n9.suma( n10);
	assert((n11.getBaza() == 2) && (n11.getNumar() == "1010"));
	
}

void Teste::test_diferenta()
{
	Numar n1("123", 4);
	Numar n2("12", 4);
	Numar n = n1.diferenta( n2);
	assert((n.getBaza() == 4) && (n.getNumar() == "111"));
	Numar n3("31F", 16);
	Numar n4("26", 16);
	Numar n5 = n3.diferenta( n4);
	assert((n5.getBaza() == 16) && (n5.getNumar() == "2F9"));
	Numar n6("1A29", 11);
	Numar n7("12A", 11);
	Numar n8 = n6.diferenta( n7);
	assert((n8.getBaza() == 11) && (n8.getNumar() == "18AA"));
	Numar n9("101", 2);
	Numar n10("1101", 2);
	Numar n11 = n9.diferenta( n10);
	assert((n11.getBaza() == 2) && (n11.getNumar() == "-1000"));

}
void Teste::test_inmultire()
{
	Numar n1("123", 4);
	Numar n = n1.inmultire('2');
	Numar n0 = n1.inmultire_cu_2_cifre("12");
	assert((n0.getBaza() == 4) && (n0.getNumar() == "2202"));
	assert((n.getBaza() == 4) && (n.getNumar() == "312"));
	Numar n3("31F", 16);
	Numar n5 = n3.inmultire( 'C');
	assert((n5.getBaza() == 16) && (n5.getNumar() == "2574"));
	Numar n6("1A29", 11);
	Numar n8 = n6.inmultire( '5');
	Numar n12 = n6.inmultire_cu_2_cifre("10");
	assert((n8.getBaza() == 11) && (n8.getNumar() == "9731"));
	assert((n12.getBaza() == 11) && (n12.getNumar() == "1A290"));
	Numar n9("101", 2);
	Numar n11 = n9.inmultire('1');
	assert((n11.getBaza() == 2) && (n11.getNumar() == "101"));
}
void Teste::test_impartire()
{
	Numar n1("123", 4);
	Numar n = n1.impartire( ' 2');
	assert((n.getBaza() == 4) && (n.getNumar() == "31"));
	Numar n3("31F", 16);
	Numar n5 = n3.impartire( 'C');
	assert((n5.getBaza() == 16) && (n5.getNumar() == "42"));
	Numar n6("1A29", 11);
	Numar n8 = n6.impartire( '5');
	assert((n8.getBaza() == 11) && (n8.getNumar() == "428"));
	Numar n9("101", 2);
	Numar n11 = n9.impartire( '1');
	assert((n11.getBaza() == 2) && (n11.getNumar() == "101"));

}
void Teste::test_impartire_rest()
{
	Numar n1("123", 4);
	Calcul n = impartire_cu_rest(n1,' 2');
	assert((n.getBaza() == 4) && (n.getNumar() == "31")&&(n.getTransport()==1));
	Numar n3("31F", 16);
	Calcul n5 = impartire_cu_rest(n3,'C');
	assert((n5.getBaza() == 16) && (n5.getNumar() == "42") && (n5.getTransport() == 7));
	Numar n6("1A29", 11);
	Calcul n8 = impartire_cu_rest(n6,'5');
	assert((n8.getBaza() == 11) && (n8.getNumar() == "428") && (n8.getTransport() == 2));
	Numar n9("101", 2);
	Calcul n11 = impartire_cu_rest(n9, '1');
	assert((n11.getBaza() == 2) && (n11.getNumar() == "101")&&(n11.getTransport() == 0));

}
void Teste::test_conversie_impartiri_succesive()
{
	Numar n1("253", 7);
	Numar n2 = conversie_impartiri_succesive(n1, "3");
	assert((n2.getBaza() == 3) && (n2.getNumar() == "12001"));
	Numar n3("157", 8);
	Numar n4 = conversie_impartiri_succesive(n3, "6");
	assert((n4.getBaza() == 6) && (n4.getNumar() == "303"));
	Numar n5("1ABC5",13);
	Numar n6 = conversie_impartiri_succesive(n5, "2");
	assert((n6.getBaza() == 2) && (n6.getNumar() == "1100110101000111"));
	Numar n7("ABCD", 16);
	Numar n8 = conversie_impartiri_succesive(n7,"10");
	assert((n8.getBaza() ==10) && (n8.getNumar() == "43981"));
	Numar n9 = conversie_impartiri_succesive(n7, "8");
	assert((n9.getBaza() == 8) && (n9.getNumar() == "125715"));
	Numar n10 = conversie_impartiri_succesive(n7, "2");
	assert((n10.getBaza() ==2) && (n10.getNumar() == "1010101111001101"));
	Numar n11 = conversie_impartiri_succesive(n7, "13");
	assert((n11.getBaza() == 13) && (n11.getNumar() == "17032"));
}
void Teste::test_conversie_substitutie()
{
	Numar n1("123", 5);
	Numar n2 = conversie_substitutie(n1, "7");
	assert((n2.getBaza() == 7) && (n2.getNumar() == "53"));
	Numar n3("157", 8);
	Numar n4 = conversie_substitutie(n3, "9");
	assert((n4.getBaza() == 9) && (n4.getNumar() == "133"));
	Numar n5("1100110101000111", 2);
	Numar n6 = conversie_substitutie(n5, "13");
	assert((n6.getBaza() == 13) && (n6.getNumar() == "1ABC5"));
	Numar n7("43981", 10);
	Numar n8 = conversie_substitutie(n7, "16");
	assert((n8.getBaza() == 16) && (n8.getNumar() == "ABCD"));
	Numar n10("125715", 8);
	Numar n9 = conversie_substitutie(n7, "10");
	assert((n9.getBaza() == 10) && (n9.getNumar() == "43981"));
}
void Teste::test_conversie_baza_intermediara()
{
	Numar n1("253", 7);
	Numar n2 = conversie_baza_intermediara(n1, "3");
	assert((n2.getBaza() == 3) && (n2.getNumar() == "12001"));
	Numar n3("157", 8);
	Numar n4 = conversie_baza_intermediara(n3, "6");
	assert((n4.getBaza() == 6) && (n4.getNumar() == "303"));
	Numar n5("1ABC5", 13);
	Numar n6 = conversie_baza_intermediara(n5, "2");
	assert((n6.getBaza() == 2) && (n6.getNumar() == "1100110101000111"));
	Numar n7("ABCD", 16);
	Numar n8 = conversie_baza_intermediara(n7, "10");
	assert((n8.getBaza() == 10) && (n8.getNumar() == "43981"));
	Numar n9 = conversie_baza_intermediara(n7, "8");
	assert((n9.getBaza() == 8) && (n9.getNumar() == "125715"));
	Numar n10 = conversie_baza_intermediara(n7, "2");
	assert((n10.getBaza() == 2) && (n10.getNumar() == "1010101111001101"));
	Numar n11 = conversie_baza_intermediara(n7, "13");
	assert((n11.getBaza() == 13) && (n11.getNumar() == "17032"));
	Numar n12("123", 5);
	Numar n13 = conversie_baza_intermediara(n12, "7");
	assert((n13.getBaza() == 7) && (n13.getNumar() == "53"));
	Numar n14("157", 8);
	Numar n15 = conversie_baza_intermediara(n14, "9");
	assert((n15.getBaza() == 9) && (n15.getNumar() == "133"));
	Numar n16("1100110101000111", 2);
	Numar n17 = conversie_baza_intermediara(n16, "13");
	assert((n17.getBaza() == 13) && (n17.getNumar() == "1ABC5"));
	Numar n18("43981", 10);
	Numar n19 = conversie_baza_intermediara(n18, "16");
	assert((n19.getBaza() == 16) && (n19.getNumar() == "ABCD"));
	Numar n20("125715", 8);
	Numar n21 = conversie_baza_intermediara(n20, "10");
	assert((n21.getBaza() == 10) && (n21.getNumar() == "43981"));
}
void Teste::test_conversie_b4_in_b2()
{
	Numar n1("123", 4);
	Numar n2 = conversie_b4_in_b2(n1);
	assert((n2.getBaza() == 2) && (n2.getNumar() == "011011"));
	Numar n3("102", 4);
	Numar n4 = conversie_b4_in_b2(n3);
	assert((n4.getBaza() == 2) && (n4.getNumar() == "010010"));
	Numar n5("3210",4);
	Numar n6 = conversie_b4_in_b2(n5);
	assert((n6.getBaza() == 2) && (n6.getNumar() == "11100100"));
	
}
void Teste::test_conversie_b2_in_b4()
{
	Numar n1("011011", 2);
	Numar n2 = conversie_b2_in_b4(n1);
	assert((n2.getBaza() == 4) && (n2.getNumar() == "123"));
	Numar n3("010010", 2);
	Numar n4 = conversie_b2_in_b4(n3);
	assert((n4.getBaza() == 4) && (n4.getNumar() == "102"));
	Numar n5("11100100", 2);
	Numar n6 = conversie_b2_in_b4(n5);
	assert((n6.getBaza() == 4) && (n6.getNumar() == "3210"));

}
void Teste::test_conversie_b8_in_b2()
{
	Numar n1("12357", 8);
	Numar n2 = conversie_b8_in_b2(n1);
	assert((n2.getBaza() == 2) && (n2.getNumar() == "001010011101111"));
	Numar n3("7", 8);
	Numar n4 = conversie_b8_in_b2(n3);
	assert((n4.getBaza() == 2) && (n4.getNumar() == "111"));
	Numar n5("56", 8);
	Numar n6 = conversie_b8_in_b2(n5);
	assert((n6.getBaza() == 2) && (n6.getNumar() == "101110"));

}
void Teste::test_conversie_b2_in_b8()
{
	Numar n1("001010011101111", 2);
	Numar n2 = conversie_b2_in_b8(n1);
	assert((n2.getBaza() == 8) && (n2.getNumar() == "12357"));
	Numar n3("111", 2);
	Numar n4 = conversie_b2_in_b8(n3);
	assert((n4.getBaza() == 8) && (n4.getNumar() == "7"));
	Numar n5("101110", 2);
	Numar n6 = conversie_b2_in_b8(n5);
	assert((n6.getBaza() == 8) && (n6.getNumar() == "56"));

}
void Teste::test_conversie_b16_in_b2()
{
	Numar n1("A1", 16);
	Numar n2 = conversie_b16_in_b2(n1);
	assert((n2.getBaza() == 2) && (n2.getNumar() == "10100001"));
	Numar n3("CD", 16);
	Numar n4 = conversie_b16_in_b2(n3);
	assert((n4.getBaza() == 2) && (n4.getNumar() == "11001101"));
	Numar n5("F", 16);
	Numar n6 = conversie_b16_in_b2(n5);
	assert((n6.getBaza() == 2) && (n6.getNumar() == "1111"));

}
void Teste::test_conversie_b2_in_b16()
{
	Numar n1("10100001", 2);
	Numar n2 = conversie_b2_in_b16(n1);
	assert((n2.getBaza() == 16) && (n2.getNumar() == "A1"));
	Numar n3("11001101", 2);
	Numar n4 = conversie_b2_in_b16(n3);
	assert((n4.getBaza() == 16) && (n4.getNumar() == "CD"));
	Numar n5("1111", 2);
	Numar n6 = conversie_b2_in_b16(n5);
	assert((n6.getBaza() == 16) && (n6.getNumar() == "F"));

}
void Teste::testClase()
{
	test_calcul();
	test_numar();
	test_nr_cif();
	test_inverseaza();
	test_adunare();
	test_diferenta();
	test_inmultire();
	test_impartire();
	test_impartire_rest();
	test_conversie_impartiri_succesive();
	test_conversie_baza_intermediara();
	test_conversie_b4_in_b2();
	test_conversie_b8_in_b2();
	test_conversie_b16_in_b2();
	test_conversie_b2_in_b4();
	test_conversie_b2_in_b8();
	test_conversie_b2_in_b16();
	test_conversie_substitutie();
}